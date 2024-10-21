import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ18428 {
    static int N;
    static int[][] map;
    static int[][] t_map;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean answer = false;


    static boolean find_student() {
        Queue<int[]> q = new ArrayDeque<>();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(t_map[i][j] == 2) {
                    q.add(new int[] {i, j});
                }
            }
        }
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                while (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    if(t_map[nx][ny] == 1) return true;
                    if(t_map[nx][ny] != 0) break;
                    else {
                        nx += dx[i];
                        ny += dy[i];
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        t_map = new int[N][N];
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                String temp = st.nextToken();
                if("S".equals(temp)) {
                    map[i][j] = 1;
                } else if("T".equals(temp)) {
                    map[i][j] = 2;
                } else {
                    map[i][j] = 0;
                }
            }
        }

        boolean flag = false;
        for(int i = 0; i < N*N; i++) {
            for(int j = i + 1; j < N*N; j++) {
                for(int k = j + 1; k < N*N; k++) {
                    for(int n = 0; n < N; n++) {
                        t_map[n] = map[n].clone();
                    }
                    int i_n = i / N, i_m = i % N;
                    int j_n = j / N, j_m = j % N;
                    int k_n = k / N, k_m = k % N;
                    if (t_map[i_n][i_m] != 0 || t_map[j_n][j_m] != 0 || t_map[k_n][k_m] != 0)
                        continue;
                    t_map[i_n][i_m] = 3;
                    t_map[j_n][j_m] = 3;
                    t_map[k_n][k_m] = 3;
                    if(!find_student()) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) System.out.println("YES");
        else System.out.println("NO");
    }
}
