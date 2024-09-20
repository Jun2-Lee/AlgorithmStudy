
import java.io.*;
import java.util.*;

public class BOJ16987 {
    static int n;
    static int[][] e_list;
    static int answer = -1;

    static void dfs(int cur, int cnt) {
        //System.out.println(cur + " " + cnt);
        answer = Math.max(cnt, answer);
        if (cur == n) {
            return;
        }
        if (e_list[cur][0] <= 0) {
            dfs(cur + 1, cnt);
            return;
        }
        for (int i = 0; i < n; i++) {
            int t_cnt = 0;
            if (i == cur)
                continue;
            if (e_list[i][0] <= 0)
                continue;
            e_list[cur][0] -= e_list[i][1];
            e_list[i][0] -= e_list[cur][1];
            if(e_list[cur][0] <= 0)
                t_cnt++;
            if(e_list[i][0] <= 0)
                t_cnt++;
            dfs(cur + 1, cnt + t_cnt);
            e_list[cur][0] += e_list[i][1];
            e_list[i][0] += e_list[cur][1];
        }

    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        e_list = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            e_list[i][0] = s;
            e_list[i][1] = w;
        }
        dfs(0, 0);
        System.out.println(answer);
    }
}
