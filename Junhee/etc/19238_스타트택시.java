import java.io.*;
import java.util.*;

public class BOJ19238 {
    static int[][] map;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int n, m, fuel;
    static int t_x, t_y;
    static int people = 0;
    static int[][] dest;

    static int find_customer(int a, int b) {
        int max_depth = Integer.MAX_VALUE;
        boolean[][] visit = new boolean[n + 1][n + 1];
        Queue<int[]> q = new ArrayDeque<>();
        if(map[a][b] > 0) {
            people = map[a][b];
            return 0;
        }
        visit[a][b] = true;
        q.add(new int[] { a, b, 0 });
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int depth = cur[2];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny] && map[nx][ny] != -1) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny, depth + 1});
                    if (map[nx][ny] > 0) {
                        if (max_depth > depth + 1) {
                            max_depth = depth + 1;
                            t_x = nx;
                            t_y = ny;
                            people = map[nx][ny];
                        }
                        else if(max_depth == depth + 1) {
                            if(t_x > nx) {
                                t_x = nx;
                                t_y = ny;
                                people = map[nx][ny];
                            }
                            else if(t_x == nx && t_y > ny) {
                                t_y = ny;
                                people = map[nx][ny];
                            }
                        }
                    }
                }
            }
        }
        return max_depth;
    }
    static int go_dest() {
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visit = new boolean[n + 1][n + 1];
        visit[t_x][t_y] = true;
        q.add(new int[] { t_x, t_y, 0 });
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int depth = cur[2];
            if(x == dest[people][0] && y == dest[people][1]) {
                map[t_x][t_y] = 0;
                t_x = x;
                t_y = y;
                return depth;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny] && map[nx][ny] != -1) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny, depth + 1});
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        fuel = Integer.parseInt(st.nextToken());
        map = new int[n + 1][n + 1];
        dest = new int[m + 1][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int temp = Integer.parseInt(st.nextToken());
                if(temp == 1)
                    map[i][j] = -1;
                else
                    map[i][j] = temp;
            }
        }
        st = new StringTokenizer(br.readLine());
        t_x = Integer.parseInt(st.nextToken()) - 1;
        t_y = Integer.parseInt(st.nextToken()) - 1;
        int cnt = 1;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s_x = Integer.parseInt(st.nextToken()) - 1;
            int s_y = Integer.parseInt(st.nextToken()) - 1;
            int d_x = Integer.parseInt(st.nextToken()) - 1;
            int d_y = Integer.parseInt(st.nextToken()) - 1;
            map[s_x][s_y] = cnt;
            dest[cnt][0] = d_x;
            dest[cnt][1] = d_y;
            cnt += 1;
        }
        int count = 0;
        while(true) {
            if(count >= m) break;
            int cost = find_customer(t_x, t_y);
            if(fuel - cost < 0) {
                fuel = -1;
                break;
            }
            fuel -= cost;
            cost = go_dest();
            if(fuel - cost < 0) {
                fuel = -1;
                break;
            }
            fuel += cost;
            count++;

        }
        System.out.println(fuel);

    }
}
