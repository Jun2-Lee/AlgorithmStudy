import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class mine {
    static int[][] map;
    static int n;
    static int[] dx = {0,1,0,-1,1,1,-1,-1};
    static int[] dy = {1,0,-1,0,1,-1,1,-1};
    static int answer = 0;

    static boolean check(int x, int y) {
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(map[nx][ny] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        map[x][y] = -1;
        int[] temp = {x, y};
        q.add(temp);

        while(!q.isEmpty()) {
            int t_x = q.peek()[0];
            int t_y = q.peek()[1];
            q.poll();
            if(check(t_x, t_y)) {
                for(int i = 0; i < 8; i++) {
                    int nx = t_x + dx[i];
                    int ny = t_y + dy[i];
                    if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if(map[nx][ny] == 0) {
                            map[nx][ny] = -1;
                            int[] n_temp = {nx, ny};
                            q.add(n_temp);
                        }
                    }
                }
            }

        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            answer = 0;
            n = Integer.parseInt(br.readLine());
            map = new int[n][n];
            for(int i = 0; i < n; i++) {
                String temp = br.readLine();
                for(int j = 0; j < n; j++) {
                    if(temp.charAt(j) == '.') {
                        map[i][j] = 0;
                    }
                    else {
                        map[i][j] = 1;
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(map[i][j] == 0 && check(i, j)) {
                        bfs(i, j);
                        answer++;
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(map[i][j] == 0) {
                        map[i][j] = -1;
                        answer++;
                    }
                }
            }
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }
}
