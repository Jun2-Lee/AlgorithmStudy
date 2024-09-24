
import java.io.*;
import java.util.*;

public class BOJ13424 {
    static int T, n, m, f;
    static int[] f_list;
    static int[][] dist;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            dist = new int[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], 123456789);
                dist[i][i] = 0;
            }
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken()) - 1;
                int e = Integer.parseInt(st.nextToken()) - 1;
                int c = Integer.parseInt(st.nextToken());
                dist[s][e] = c;
                dist[e][s] = c;
            }
            f = Integer.parseInt(br.readLine());
            f_list = new int[f];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < f; i++) {
                f_list[i] = Integer.parseInt(st.nextToken()) - 1;
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            int answer = -1;
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         System.out.print(dist[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            int cnt = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int temp = 0;
                for (int j = 0; j < f; j++) {
                    //System.out.print(f_list[j] + " ");
                    temp += dist[i][f_list[j]];
                }
                //System.out.println(temp);
                if (cnt > temp) {
                    answer = i + 1;
                    cnt = temp;
                }
            }
            System.out.println(answer);
        }
    }
}
