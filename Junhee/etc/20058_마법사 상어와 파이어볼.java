
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ20058 {
    static int N, Q, L;
    static int[][] map;
    static int[][] rotate_map;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static boolean[][] visit;

    static boolean is_in(int x, int y) {
        if (0 <= x && x < N && 0 <= y && y < N) {
            return true;
        }
        return false;

    }

    static int find_near(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny)) {
                if (map[nx][ny] > 0)
                    cnt++;
            }
        }
        return cnt;
    }

    static void melt() {
        boolean[][] t_map = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (find_near(i, j) < 3 && map[i][j] > 0) {
                    t_map[i][j] = true;
                    //map[i][j]--;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (t_map[i][j])
                    map[i][j]--;
            }
        }
    }

    static void rotate(int x, int y, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                rotate_map[x + j][y + size - i - 1] = map[x + i][y + j];
            }
        }
    }

    static int bfs(int sx, int sy) {
        int cnt = 0;
        Queue<int[]> q = new ArrayDeque<>();
        visit[sx][sy] = true;
        q.add(new int[] { sx, sy });
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            cnt++;
            int x = cur[0];
            int y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (is_in(nx, ny) && !visit[nx][ny] && map[nx][ny] > 0) {
                    visit[nx][ny] = true;
                    q.add(new int[] { nx, ny });
                }
            }
        }
        
        return cnt;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        N = (int) Math.pow(2, N);
        Q = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < Q; i++) {
            rotate_map = new int[N][N];
            L = Integer.parseInt(st.nextToken());
            L = (int) Math.pow(2, L);
            for (int a = 0; a < N; a += L) {
                for (int b = 0; b < N; b += L) {
                    rotate(a, b, L);
                }
            }
            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    map[a][b] = rotate_map[a][b];
                }
            }
            melt();
        }
        
        int answer1 = 0;
        int answer2 = 0;
        visit = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j] && map[i][j] > 0) {
                    answer2 = Math.max(bfs(i, j), answer2);
                }
                answer1 += map[i][j];
            }
        }
        System.out.println(answer1);
        System.out.println(answer2);
    }
}
