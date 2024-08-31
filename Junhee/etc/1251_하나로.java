import java.io.*;
import java.util.*;

public class SWEA1251 {

    static class Edge implements Comparable<Edge>{
        int node;
        double w;

        public Edge(int node, double w) {
            this.node = node;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return Double.compare(this.w, o.w);
        }
    }

    static int v, e;
    static double rate;
    static double answer;
    static ArrayList<Edge>[] list;
    static int[] x;
    static int[] y;
    static boolean[] visit;
    static double l;

    static void prim(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        visit[start] = true;
        for(int i = 0; i < list[start].size(); i++) {
            pq.add(list[start].get(i));
        }
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            // System.out.println(cur.node + " " + cur.w);
            if(visit[cur.node]) {
                continue;
            }
            answer += cur.w;
            visit[cur.node] = true;
            for(int i = 0; i < list[cur.node].size(); i++) {
                if(visit[list[cur.node].get(i).node])
                    continue;
                pq.add(list[cur.node].get(i));
            }
        }
    }

    static double make_edge(int x1, int x2, int y1, int y2) {
        double w = Math.pow(Math.abs(x1 - x2), 2) + Math.pow(Math.abs(y1 - y2), 2);
        return w * rate;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            answer = 0;
            v = Integer.parseInt(br.readLine());
            visit = new boolean[v];
            list = new ArrayList[v];
            x = new int[v];
            y = new int[v];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < v; i++) {
                list[i] = new ArrayList<>();
                x[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < v; i++) {
                y[i] = Integer.parseInt(st.nextToken());
            }
            rate = Double.parseDouble(br.readLine());
            for (int i = 0; i < v; i++) {
                for(int j = i + 1; j < v; j++) {
                    double dist = make_edge(x[i], x[j], y[i], y[j]);
                    list[i].add(new Edge(j, dist));
                    list[j].add(new Edge(i, dist));
                }
            }
            // for(int i = 0; i < v; i++) {
            //     for(int j = 0; j < list[i].size(); j++) {
            //         System.out.println(list[i].get(j).node);
            //     }
            // }
            prim(0);
            sb.append("#").append(t).append(" ").append(Math.round(answer)).append("\n");
        }
        System.out.println(sb);
    }
}
