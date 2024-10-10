import java.util.*;
import java.io.*;

public class BOJ1726 {
    static int n, m;
    static int[][] map;
    static int[] start = new int[3];
    static int[] dest = new int[3];
    static int[] dx = {0,0,0,1,-1};
    static int[] dy = {0,1,-1,0,0};
    static int answer = 0;

    static void bfs() {
        boolean[][][] visit = new boolean[n][m][5];
        Queue<int[]> q = new ArrayDeque<>();
        visit[start[0]][start[1]][start[2]] = true;
        q.add(new int[] {start[0], start[1], start[2], 0});
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int dir = cur[2];
            int depth = cur[3];
            if(x == dest[0] && y == dest[1] && dir == dest[2]) {
                answer = depth;
                return;
            }
            for(int i = 1; i <= 3; i++) {
                int nx = x + dx[dir] * i;
                int ny = y + dy[dir] * i;
                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(map[nx][ny] == 1) break;
                    if(map[nx][ny] == 0 && !visit[nx][ny][dir]) {
                        visit[nx][ny][dir] = true;
                        q.add(new int[] {nx, ny, dir, depth + 1});
                    }
                }
            }
            if(dir == 1 || dir == 2) {
                if(!visit[x][y][3]) {
                    visit[x][y][3] = true;
                    q.add(new int[] {x, y, 3, depth + 1});
                }
                if(!visit[x][y][4]) {
                    visit[x][y][4] = true;
                    q.add(new int[] {x, y, 4, depth + 1});
                }
            }
            if(dir == 3 || dir == 4) {
                if(!visit[x][y][1]) {
                    visit[x][y][1] = true;
                    q.add(new int[] {x, y, 1, depth + 1});
                }
                if(!visit[x][y][2]) {
                    visit[x][y][2] = true;
                    q.add(new int[] {x, y, 2, depth + 1});
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 3; i++) {
            start[i] = Integer.parseInt(st.nextToken());
        }
        start[0]--; start[1]--;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 3; i++) {
            dest[i] = Integer.parseInt(st.nextToken());
        }
        dest[0]--; dest[1]--;
        bfs();
        System.out.println(answer);
    }
}
