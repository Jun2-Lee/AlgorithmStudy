import java.util.*;

class Solution {
    int[][] map = new int[100][100];
    int n, m;
    int[] dx = {0,1,0,-1};
    int[] dy = {1,0,-1,0};
    ArrayList<Integer> t_answer = new ArrayList<>();
    
    public void bfs(int sx, int sy) {
        int cnt = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {sx, sy});
        cnt += map[sx][sy];
        map[sx][sy] = -1;
        
        while(!q.isEmpty()) {
            int[] temp = q.peek();
            int x = temp[0], y = temp[1];
            q.remove();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(map[nx][ny] != -1) {
                        cnt += map[nx][ny];
                        q.add(new int[] {nx, ny});
                        map[nx][ny] = -1;
                    }
                }
            }
        }
        t_answer.add(cnt);
    }
    
    public int[] solution(String[] maps) {
        n = maps.length;
        m = maps[0].length();
        for(int i = 0; i < maps.length; i++) {
            for(int j = 0; j < maps[i].length(); j++) {
                if(maps[i].charAt(j) == 'X') {
                    map[i][j] = -1;
                }
                else{
                    map[i][j] = maps[i].charAt(j) - '0';
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] != -1) {
                    bfs(i, j);
                }
            }
        }
        
        int[] answer = new int[t_answer.size()];
        for(int i = 0; i < t_answer.size(); i++) {
            answer[i] = t_answer.get(i);
        }
        Arrays.sort(answer);
        if(answer.length == 0) {
            answer = new int[] {-1};
        }
        return answer;
    }
}
