import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ17142 {
    static int n, m;
    static int[][] map;
    static ArrayList<int[]> virus = new ArrayList<>();
    static ArrayList<Integer> comb = new ArrayList<>();
    static boolean[] visit;
    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };
    static int answer = Integer.MAX_VALUE;
    static int[][] temp_map;

    static void check_map() {
        int temp_ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > 0) {
                    temp_map[i][j] = -1;
                }
                if (temp_map[i][j] == 0)
                    return;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp_map[i][j] < 0)
                    continue;
                temp_ans = Math.max(temp_ans, temp_map[i][j]);
            }
        }
        answer = Math.min(answer, temp_ans);
    }

    static void bfs() {
        temp_map = new int[n][n];
        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < comb.size(); i++) {
            q.add(new int[] { virus.get(comb.get(i))[0], virus.get(comb.get(i))[1], 0 });
        }
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int depth = cur[2];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (map[nx][ny] == 1 || temp_map[nx][ny] != 0)
                        continue;
                    temp_map[nx][ny] = depth + 1;
                    q.add(new int[] { nx, ny, depth + 1 });
                }
            }
        }
        check_map();
    }
    static void dfs(int start) {
        if (comb.size() == m) {
            bfs();
            return;
        }
        for (int i = start; i < virus.size(); i++) {
            if (visit[i])
                continue;
            visit[i] = true;
            comb.add(i);
            dfs(i);
            comb.remove(comb.size() - 1);
            visit[i] = false;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int temp = Integer.parseInt(st.nextToken());
                map[i][j] = temp;
                if (temp == 2) {
                    virus.add(new int[] { i, j });
                }
            }
        }
        visit = new boolean[virus.size()];
        dfs(0);
        if(answer == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(answer);
    }
}
