import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class SWEA3124 {

    static class Edge implements Comparable<Edge>{
        int node, w;

        public Edge(int node, int w) {
            this.node = node;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.w - o.w;
        }
    }

    static boolean[] visit;
    static int v, e;
    static long answer;
    static ArrayList<Edge>[] e_list;

    static void prim(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        visit[start] = true;
        for(int i = 0; i < e_list[start].size(); i++) {
            pq.add(e_list[start].get(i));
        }
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            //System.out.println(cur.node + " " + cur.w);
            if(visit[cur.node]) {
                continue;
            }
            answer += cur.w;
            visit[cur.node] = true;
            for(int i = 0; i < e_list[cur.node].size(); i++) {
                if(visit[e_list[cur.node].get(i).node])
                    continue;
                pq.add(e_list[cur.node].get(i));
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            e_list = new ArrayList[v + 1];
            for(int i = 0; i <= v; i++) {
                e_list[i] = new ArrayList<>();
            }
            visit = new boolean[v + 1];
            answer = 0;
            for(int i = 0; i < e; i++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                e_list[s].add(new Edge(d, w));
                e_list[d].add(new Edge(s, w));
            }
            prim(1);
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }
}
