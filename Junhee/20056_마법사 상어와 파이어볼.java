import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ20056 {
    static class Fire implements Comparable<Fire>{
        int x, y, m, dir, s, pos;

        public Fire(int x, int y, int m, int dir, int s, int pos) {
            this.x = x;
            this.y = y;
            this.m = m;
            this.dir = dir;
            this.s = s;
            this.pos = pos;
        }

        @Override
        public int compareTo(Fire o) {
            return this.pos - o.pos;
        }
    }
    static int n, m, k;
    static int[][] map;
    static ArrayList<Fire> f_list;
    static int[][] d = {{-1, 0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

    static ArrayList<Fire> move() {
        ArrayList<Fire> m_list = new ArrayList<>();
        for(Fire f : f_list) {
            int x = f.x;
            int y = f.y;
            int dx = d[f.dir][0];
            int dy = d[f.dir][1];
            int nx = (x + (dx * f.s)) % n;
            int ny = (y + (dy * f.s)) % n;
            while(nx < 0) nx = n + nx;
            while(ny < 0) ny = n + ny;
            m_list.add(new Fire(nx, ny, f.m, f.dir, f.s, nx * n + ny));
        }
        Collections.sort(m_list);

        return m_list;
    }

    static ArrayList<Fire> play() {
        ArrayList<Fire> res_list = new ArrayList<>();
        int start = 0, cnt = 1;
        boolean f1 = false;
        for(int i = 0; i < f_list.size() - 1; i++) {
            if (start + cnt < f_list.size()) {
                if (f_list.get(start).pos == f_list.get(start + cnt).pos) {
                    cnt++;
                    f1 = true;
                } else if (cnt >= 2) {
                    //System.out.println("fire");
                    f1 = false;
                    int t_x, t_y, t_m = 0, t_s = 0, t_dir;
                    boolean flag = false;
                    t_x = f_list.get(start).x;
                    t_y = f_list.get(start).y;
                    t_dir = f_list.get(start).dir % 2;
                    for (int j = 0; j < cnt; j++) {
                        t_m += f_list.get(start + j).m;
                        t_s += f_list.get(start + j).s;
                        if (t_dir != f_list.get(start + j).dir % 2) flag = true;
                    }
                    for (int j = 0; j < 4; j++) {
                        if (t_m / 5 == 0) break;
                        if (flag) {
                            res_list.add(new Fire(t_x, t_y, t_m / 5, j * 2 + 1, t_s / cnt, t_x * n + t_y));
                        } else {
                            res_list.add(new Fire(t_x, t_y, t_m / 5, j * 2, t_s / cnt, t_x * n + t_y));
                        }
                    }
                    start = i + 1;
                    cnt = 1;
                } else {
                    //System.out.println("just f");
                    start = i + 1;
                    res_list.add(f_list.get(i));
                }
                //System.out.println(start + " " + cnt);
            }
        }
        if(f1) {
            //System.out.println("fire2");
            int t_x, t_y, t_m = 0, t_s = 0, t_dir;
            boolean flag = false;
            t_x = f_list.get(start).x;
            t_y = f_list.get(start).y;
            t_dir = f_list.get(start).dir % 2;
            for(int j = 0; j < cnt; j++) {
                t_m += f_list.get(start + j).m;
                t_s += f_list.get(start + j).s;
                if(t_dir != f_list.get(start + j).dir % 2) flag = true;
            }
            for(int j = 0; j < 4; j++) {
                if(t_m / 5 == 0) break;
                if(flag) {
                    res_list.add(new Fire(t_x, t_y, t_m / 5, j * 2 + 1, t_s / cnt, t_x * n + t_y));
                }
                else {
                    res_list.add(new Fire(t_x, t_y, t_m / 5, j * 2, t_s / cnt, t_x * n + t_y));
                }
            }
        }
        else {
            //System.out.println("final");
            res_list.add(f_list.get(f_list.size() - 1));
        }
        return res_list;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new int[n][n];
        f_list = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int m = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int dir = Integer.parseInt(st.nextToken());
            f_list.add(new Fire(x,y,m,dir,s,x * n + y));
        }
        for(int j = 0; j < k; j++) {
            f_list = move();
//            for (int i = 0; i < f_list.size(); i++) {
//                System.out.println(f_list.get(i).x + " " + f_list.get(i).y + " " + f_list.get(i).m + " " + f_list.get(i).s + " " + f_list.get(i).dir + " " + f_list.get(i).pos);
//            }
            if(f_list.isEmpty()) break;
            f_list = play();
            if(f_list.size() == 0) break;
            //System.out.println("========================================");
        }
        int answer = 0;
        for(Fire f : f_list) {
            answer += f.m;
        }
        System.out.println(answer);
    }
}
