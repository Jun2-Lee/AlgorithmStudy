import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ10971 {

    static int n;
    static int[][] map;
    static boolean[] visit;
    static int answer = Integer.MAX_VALUE;

    static void dfs(int start, int cur, int depth, int cost) {
        if (depth == n) {
            if (map[cur][start] != 0) {
                answer = Math.min(answer, cost + map[cur][start]);
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i] && map[cur][i] != 0) {  // 경로가 있고, 방문하지 않은 도시만 탐색
                visit[i] = true;
                dfs(start, i, depth + 1, cost + map[cur][i]);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < n; i++) {
            visit[i] = true;  // 시작점을 방문 처리
            dfs(i, i, 1, 0);  // depth는 1로 시작
            visit[i] = false;
        }
        System.out.println(answer);
    }
}
