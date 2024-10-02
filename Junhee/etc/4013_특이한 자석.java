import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA4013 {
    static int T;
    static int K;
    static int[][] wheel = new int[4][8];
    static boolean[] visit;

    static void rotate(int num, int dir) {
        if(num == -1 || num == 4) return;
        if(visit[num]) return;
        visit[num] = true;
        //System.out.println("num = " + num);
        if(num < 3 && wheel[num][2] != wheel[num + 1][6]) {
            rotate(num + 1, -1 * dir);
        }
        if(num > 0 && wheel[num][6] != wheel[num - 1][2]) {
            rotate(num - 1, -1 * dir);
        }
        if(dir == 1) {
            int temp = wheel[num][7];
            for(int i = 7; i > 0; i--) {
                wheel[num][i] = wheel[num][i - 1];
            }
            wheel[num][0] = temp;
        }
        else {
            int temp = wheel[num][0];
            for(int i = 0; i < 7; i++) {
                wheel[num][i] = wheel[num][i + 1];
            }
            wheel[num][7] = temp;
        }
    }

    static int calc() {
//        for(int i = 0; i < 4; i++) {
//            for(int j = 0; j < 8; j++) {
//                System.out.print(wheel[i][j] + " ");
//            }
//            System.out.println();
//        }
        int idx = 1;
        int score = 0;
        for(int i = 0; i < 4; i++) {
            score += idx * wheel[i][0];
            idx *= 2;
        }
        return score;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            K = Integer.parseInt(br.readLine());
            for(int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < 8; j++) {
                    wheel[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int i = 0; i < K; i++) {
                visit = new boolean[4];
                st = new StringTokenizer(br.readLine());
                int num = Integer.parseInt(st.nextToken()) - 1;
                int dir = Integer.parseInt(st.nextToken());
                rotate(num, dir);
//                for(int k = 0; k < 4; k++) {
//                    for(int j = 0; j < 8; j++) {
//                        System.out.print(wheel[k][j] + " ");
//                    }
//                    System.out.println();
//                }
            }
            sb.append("#").append(t).append(" ").append(calc()).append("\n");
        }
        System.out.println(sb.toString());

    }
}
