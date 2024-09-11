import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Cheese {

    static int n, m;
    static int[][] map = new int[101][101];
    static boolean[][] visit;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    static boolean check_cheese() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1)
                    return false;
            }
        }
        return true;
    }

    static void check_melt() {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (map[x][y] != 2)
                    continue;
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if (visit[nx][ny] && map[nx][ny] == 0) {
                            cnt++;
                        }
                    }
                }
                if (cnt < 2)
                    map[x][y] = 1;
            }
        }
    }

    static void melt_cheese() {
        visit = new boolean[n][m];
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] { 0, 0 });
        visit[0][0] = true;
        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !visit[nx][ny]) {
                    if (map[nx][ny] == 1) {
                        visit[nx][ny] = true;
                        map[nx][ny] = 2;
                    } else {
                        visit[nx][ny] = true;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
        }
    }
    
    static void melt() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 2)
                    map[i][j] = 0;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int answer = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (!check_cheese()) {
            melt_cheese();
            check_melt();
            melt();
            answer++;
        }

        System.out.println(answer);
    }
}
