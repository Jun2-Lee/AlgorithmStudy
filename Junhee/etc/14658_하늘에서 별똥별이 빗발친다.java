import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ14658 {
    static int n, m, l, k;
    static int[][] star_list;
    static int answer = 0;

    static void search_star(int[] first, int[] second) {
        int cnt = 0;
        int s_x = Math.min(first[0], second[0]);
        int s_y = Math.min(first[1], second[1]);
        int e_x = s_x + l;
        int e_y = s_y + l;
        for (int i = 0; i < k; i++) {
            int x = star_list[i][0];
            int y = star_list[i][1];
            if (s_x <= x && x <= e_x && s_y <= y && y <= e_y) {
                cnt++;
            }
        }
        answer = Math.max(answer, cnt);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        star_list = new int[k][2];
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            star_list[i][0] = x;
            star_list[i][1] = y;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                search_star(star_list[i], star_list[j]);
            }
        }
        System.out.println(k - answer);
    }
}
