import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ32288 {
    static int n, m, k;
    static int[][] map = new int[21][21];
    static int[] dice = { 2, 4, 1, 3, 5, 6 };
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static int dir = 0;
    static int x = 0;
    static int y = 0;
    static int answer = 0;
    static boolean visit[][];

    static void roll() {
        int temp;
        switch (dir) {
            case 0:
                temp = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[2];
                dice[2] = dice[1];
                dice[1] = temp;
                break;
            case 1:
                temp = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[3];
                dice[3] = temp;
                break;
            case 2:
                temp = dice[0];
                dice[0] = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[2];
                dice[2] = temp;
                break;
            case 3:
                temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[4];
                dice[4] = dice[5];
                dice[5] = temp;
                break;
        }
    }

    static void turn() {
        if (dice[5] > map[x][y]) {
            switch (dir) {
                case 0:
                    dir = 2;
                    break;
                case 1:
                    dir = 3;
                    break;
                case 2:
                    dir = 1;
                    break;
                case 3:
                    dir = 0;
                    break;
            }
        }
        if (dice[5] < map[x][y]) {
            switch (dir) {
                case 0:
                    dir = 3;
                    break;
                case 1:
                    dir = 2;
                    break;
                case 2:
                    dir = 0;
                    break;
                case 3:
                    dir = 1;
                    break;
            }
        }
    }

    static void go() {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            x = nx;
            y = ny;
        } else {
            switch (dir) {
                case 0:
                    dir = 1;
                    break;
                case 1:
                    dir = 0;
                    break;
                case 2:
                    dir = 3;
                    break;
                case 3:
                    dir = 2;
                    break;
            }
            x += dx[dir];
            y += dy[dir];

        }
    }
    
    static void calc() {
        visit = new boolean[21][21];
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] { x, y });
        visit[x][y] = true;
        answer += map[x][y];
        while (!q.isEmpty()) { 
            int[] cur = q.poll();
            int c_x = cur[0];
            int c_y = cur[1];
            //System.out.println(c_x + " " + c_y);
            for (int i = 0; i < 4; i++) {
                int nx = c_x + dx[i];
                int ny = c_y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
                        answer += map[x][y];
                        q.add(new int[] { nx, ny });
                    }
                    visit[nx][ny] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < k; i++) {
            go();
            roll();
            turn();
            calc();
        }
        System.out.println(answer);
    }
}
