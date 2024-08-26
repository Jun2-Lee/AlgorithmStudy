import java.io.*;
import java.util.*;

public class cheese {
    static int[][] map;
    static int N;
    static int[] dx = { 1, -1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };
    static int answer = 1;

    static class Coordinate {
        int x;
        int y;

        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    static boolean inRange(int i, int j) {
        return i >= 0 && j >= 0 && i < N & j < N;
    }


    static void bfs(int num){
        Queue<Coordinate> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];

        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || map[i][j] <= num) {
                    continue;
                }

                visited[i][j] = true;
                q.add(new Coordinate(i, j));

                while (!q.isEmpty()) {
                    int x = q.peek().x;
                    int y = q.peek().y;
                    q.poll();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (!inRange(nx, ny) || visited[nx][ny]) {
                            continue;
                        }

                        if (map[nx][ny] <= num) {
                            visited[nx][ny] = true;
                            continue;
                        }

                        q.add(new Coordinate(nx, ny));
                        visited[nx][ny] = true;

                    }
                }
                cnt++;
            }
        }
        answer = Math.max(answer, cnt);
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
    
        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            answer = 1;
            N = Integer.parseInt(br.readLine());
            map = new int[N][N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 1; i <= 100; i++) {
                bfs(i);
            }
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }
}
