
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA1238 {
    static int n, start;
    static int[][] map;
    static int[] visit;
    static int max_p;
    static int max_len;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static void bfs(int s_p) {
        Queue<Integer> q = new ArrayDeque<>();
        visit[s_p] = 0;
        q.add(s_p);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 1; i <= max_p; i++) {
                if (map[cur][i] == 1 && visit[i] == -1) {
                    visit[i] = visit[cur] + 1;
                    q.add(i);
                    max_len = Math.max(max_len, visit[i]);
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        StringBuilder sb = new StringBuilder();
        for (int t = 1; t <= 10; t++) {
            visit = new int[101];
            map = new int[101][101];
            max_p = -1;
            max_len = -1;
            Arrays.fill(visit, -1);
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i += 2) {
                int s = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                max_p = Math.max(max_p, Math.max(s, d));
                map[s][d] = 1;
            }
            bfs(start);
            for (int i = max_p; i > 0; i--) {
                if (visit[i] == max_len) {
                    sb.append("#").append(t).append(" ").append(i).append("\n");
                    break;
                }
            }
        }
        System.out.println(sb);
    }
}
