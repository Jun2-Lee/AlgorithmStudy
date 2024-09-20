import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Chess {
    static int n, m, k;
    static char[][] map;
    static int[][] t_map;
    static int answer = Integer.MAX_VALUE;
    static void calc() {
        for(int i = 1; i < n - k + 2; i++) {
            for(int j = 1; j < m - k + 2; j++) {
                int temp = t_map[i + k -1][j + k - 1] - t_map[i - 1][j + k - 1] - t_map[i + k - 1][j - 1] + t_map[i - 1][j - 1];
                answer = Math.min(answer, temp);
            }
        }
    }
    static void prefix_black() {
        t_map = new int[n + 1][m + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i + j) % 2 == 0) {
                    if(map[i][j] == 'B')
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j];
                    else
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j] + 1;
                }
                else {
                    if(map[i][j] == 'B')
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j] + 1;
                    else
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j];
                }
            }
        }
        /*for(int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                System.out.print(t_map[i][j] + " ");
            }
            System.out.println();
        }*/
        calc();

    }

    static void prefix_white() {
        t_map = new int[n + 1][m + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i + j) % 2 == 0) {
                    if(map[i][j] == 'W')
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j];
                    else
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j] + 1;
                }
                else {
                    if(map[i][j] == 'W')
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j] + 1;
                    else
                        t_map[i + 1][j + 1] = t_map[i + 1][j] + t_map[i][j + 1] - t_map[i][j];
                }
            }
        }
        calc();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new char[n][m];
        for(int i = 0; i < n; i++) {
            String s = br.readLine();
            for(int j = 0; j < m; j++) {
                map[i][j] = s.charAt(j);
            }
        }
        prefix_black();
        prefix_white();
        System.out.println(answer);
    }

}
