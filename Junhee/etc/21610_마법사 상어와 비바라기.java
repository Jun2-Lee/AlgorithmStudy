import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ21610 {
    static int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int n, m, d, s;
    static int[][] map;
    static boolean[][] visit;
    static ArrayList<int[]> cloud = new ArrayList<>();

    static void move_rain() {
        for (int[] c : cloud) {
            c[0] += dx[d] * s;
            c[1] += dy[d] * s;
            while (c[0] < 0) c[0] += n;
            while (c[1] < 0) c[1] += n;
            c[0] %= n;
            c[1] %= n;
            visit[c[0]][c[1]] = true;
            map[c[0]][c[1]]++;
        }
    }

    static void copy_water() {
        for(int[] c : cloud) {
            for(int i = 0; i < 4; i++) {
                int nx = c[0] + dx[i * 2 + 1];
                int ny = c[1] + dy[i * 2 + 1];
                if(0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] > 0) {
                    map[c[0]][c[1]]++;
                }
            }
        }
    }

    static void make_cloud() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] >= 2 && !visit[i][j]) {
                    map[i][j] -= 2;
                    cloud.add(new int[] {i, j});
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        visit = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cloud.add(new int[]{n - 1, 0});
        cloud.add(new int[]{n - 1, 1});
        cloud.add(new int[]{n - 2, 0});
        cloud.add(new int[]{n - 2, 1});
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            d = Integer.parseInt(st.nextToken()) - 1;
            s = Integer.parseInt(st.nextToken());
            move_rain();
            copy_water();
            cloud.clear();
            make_cloud();
            visit = new boolean[n][n];
        }
        int answer = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                answer += map[i][j];
            }
        }
        System.out.println(answer);
    }
}
