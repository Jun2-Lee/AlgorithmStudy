import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Virus {
    static int n, m;
    static int[][] list = new int[101][101];
    static boolean[] visit = new boolean[101];
    static int answer = -1;

    static void dfs(int idx) {
        answer++;
        for(int i = 1; i <= n; i++) {
            if(list[idx][i] == 1 && !visit[i]) {
                visit[i] = true;
                dfs(i);
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            list[s][d] = 1;
            list[d][s] = 1;
        }
        visit[1] = true;
        dfs(1);
        System.out.println(answer);
    }
    
}
