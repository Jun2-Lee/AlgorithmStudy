import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA3289 {
    static int[] node;
    static int n, m;

    static int find(int v) {
        if (v == node[v])
            return v;
        else
            return node[v] = find(node[v]);
    }

    static void union(int a, int b) {
        int ua = find(a);
        int ub = find(b);
        if (ua != ub)
            node[ua] = ub;
    }

    static void init() {
        for (int i = 1; i < node.length; i++) {
            node[i] = i;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            StringBuilder t_sb = new StringBuilder();
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            node = new int[n + 1];
            init();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int oper = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                if (oper == 0) {
                    union(s, d);
                } else {
                    int fs = find(s);
                    int fd = find(d);
                    if (fs == fd) {
                        t_sb.append("1");
                    } else {
                        t_sb.append("0");
                    }
                }
            }
            sb.append("#").append(t).append(" ").append(t_sb).append("\n");
        }
        System.out.println(sb);
    }
}
