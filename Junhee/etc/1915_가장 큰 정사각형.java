import java.util.*;
import java.io.*;;

public class BOJ1915 {
    static int n, m;
    static int[][] map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        for(int i = 0; i < n; i++) {
            String s = br.readLine();
            for(int j = 0; j < m; j++) {
                if(s.charAt(j) == '0')
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(map[i][j] != 0)
                    map[i][j] = Math.min(Math.min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
            }
        }
        int answer = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //System.out.print(map[i][j] + " ");
                answer = Math.max(answer, map[i][j]);
            }
            //System.out.println();
        }
        System.out.println(answer * answer);
    }
}
