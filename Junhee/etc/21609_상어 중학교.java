import java.io.*;
import java.util.*;

public class BOJ21609 {
    static int n, m;
    static int[][] map;
    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };
    static boolean[][] visit;
    static int max_cnt = 0;
    static int max_rainbow_cnt = 0;
    static int delete_x = -1, delete_y = -1;
    static int score = 0;

    static void find_block(int sx, int sy) {
        int cnt = 0;
        int rainbow_cnt = 0;
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] { sx, sy });
        visit[sx][sy] = true;
        cnt++;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (!visit[nx][ny] && map[nx][ny] == map[sx][sy]) {
                        visit[nx][ny] = true;
                        cnt++;
                        q.add(new int[] { nx, ny });
                    } else if (!visit[nx][ny] && map[nx][ny] == 0) {
                        visit[nx][ny] = true;
                        cnt++;
                        rainbow_cnt++;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] == 0)
                    visit[i][j] = false;
            }
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_rainbow_cnt = rainbow_cnt;
            delete_x = sx;
            delete_y = sy;
        } else if (cnt == max_cnt && rainbow_cnt > max_rainbow_cnt) {
            max_rainbow_cnt = rainbow_cnt;
            delete_x = sx;
            delete_y = sy;
        } else if (cnt == max_cnt && rainbow_cnt == max_rainbow_cnt) {
            delete_x = sx;
            delete_y = sy;
        }

    }
    
    static void delete_block(int sx, int sy) {
        boolean[][] visit = new boolean[n][n];
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] { sx, sy });
        int color = map[sx][sy];
        visit[sx][sy] = true;
        map[sx][sy] = -2;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (!visit[nx][ny] && (map[nx][ny] == color || map[nx][ny] == 0)) {
                        visit[nx][ny] = true;
                        map[nx][ny] = -2;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
        }
        score += max_cnt * max_cnt;
    }

    static void swap_down(int x, int y) {
        for (int i = x + 1; i < n; i++) {
            if (map[i][y] == -2) {
                int temp = map[i][y];
                map[i][y] = map[i - 1][y];
                map[i - 1][y] = temp;
            }
            else {
                break;
            }
        }
    }

    static void gravity() {
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] >= 0) {
                    swap_down(i, j);
                }
            }
        }
    }
    
    static void turn() {
        int[][] tmp_arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                tmp_arr[n - 1 - j][i] = map[i][j];
        }
        map = tmp_arr;
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
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        while (true) {
            visit = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][j] > 0)
                        find_block(i, j);
                }
            }
            if (max_cnt < 2) {
                System.out.println(score);
                break;
            }
            delete_block(delete_x, delete_y);
            gravity();
            turn();
            gravity();
            max_cnt = 0;
            max_rainbow_cnt = 0;
            delete_x = -1;
            delete_y = -1;
        }
        
    }
}
