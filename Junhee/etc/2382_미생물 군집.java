import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class SWEA2382 {
    static class Virus implements Comparable<Virus>{
        int x, y, cnt, dir, pos;

        public Virus(int x, int y, int cnt, int dir, int pos) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.dir = dir;
            this.pos = pos;
        }
        
        @Override
        public int compareTo(Virus o) {
            if (this.pos == o.pos) {
                return o.cnt - this.cnt;
            }
            return this.pos - o.pos;
        }
    }
 
    static int n, m, k;
    static ArrayList<Virus> v_list;
    static int[][] d = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
 
    static void play() {
        for (int i = 0; i < m; i++) {
            ArrayList<Virus> remove_v = new ArrayList<>();
            for (Virus v : v_list) {
                v.x = v.x + d[v.dir - 1][0];
                v.y = v.y + d[v.dir - 1][1];

                if (is_side(v.x, v.y)) {
                    switch (v.dir) {
                        case 1:
                            v.dir = 2;
                            break;
                        case 2:
                            v.dir = 1;
                            break;
                        case 3:
                            v.dir = 4;
                            break;
                        case 4:
                            v.dir = 3;
                            break;
                    }
                    v.cnt /= 2;
                }
                if (v.cnt == 0) {
                    remove_v.add(v);
                }
                v.pos = (v.x * n) + v.y;
            }
            for (Virus v : remove_v) {
                v_list.remove(v);
            }
            Collections.sort(v_list);
            for (int j = 0; j < v_list.size() - 1; j++) {
                Virus v1 = v_list.get(j);
                Virus v2 = v_list.get(j + 1);
                if (v1.pos == v2.pos) {
                    v1.cnt += v2.cnt;
                    v_list.remove(j + 1);
                    j--;
                }
            }
        }

    }
    
    static boolean is_side(int x, int y) {
        return x == 0 || y == 0 || x == n - 1 || y == n - 1;
    }
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            v_list = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int t_x = Integer.parseInt(st.nextToken());
                int t_y = Integer.parseInt(st.nextToken());
                int t_c = Integer.parseInt(st.nextToken());
                int t_d = Integer.parseInt(st.nextToken());
                v_list.add(new Virus(t_x, t_y, t_c, t_d, t_x * n + t_y));
            }
            play();
            int answer = 0;
            for (Virus v : v_list) {
                answer += v.cnt;
            }
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
         
    }
}
