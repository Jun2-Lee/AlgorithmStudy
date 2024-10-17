import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1504 {
    static class Node implements Comparable<Node>{
        int dest, cost;
        Node(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
    static int N, E;
    static ArrayList<Node>[] list;
    static int[] V = new int[2];
    static int answer = 0;
    static int dijkstra(int start, int dest) {
        int[] dist = new int[N];
        boolean[] visit = new boolean[N];
        Arrays.fill(dist, 200000001);
        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        while(!pq.isEmpty()){
            int cur = pq.poll().dest;
            visit[cur] = true;
            for(Node next : list[cur]) {
                if(dist[next.dest] > dist[cur] + next.cost) {
                    dist[next.dest] = dist[cur] + next.cost;
                    pq.add(new Node(next.dest, dist[next.dest]));
                }
            }
        }
//        for(int i = 0; i < N; i++) {
//            System.out.print(dist[i] + " ");
//        }
//        System.out.println();
        return dist[dest];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        list = new ArrayList[N];
        for(int i = 0; i < N; i++) {
            list[i] = new ArrayList<>();
        }
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()) - 1;
            int e = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            list[s].add(new Node(e, c));
            list[e].add(new Node(s, c));
        }
        st = new StringTokenizer(br.readLine());
        V[0] = Integer.parseInt(st.nextToken()) - 1;
        V[1] = Integer.parseInt(st.nextToken()) - 1;

        answer = Math.min(dijkstra(0, V[0]) + dijkstra(V[0], V[1]) + dijkstra(V[1], N - 1),
                dijkstra(0, V[1]) + dijkstra(V[1], V[0]) + dijkstra(V[0], N - 1));
        if(answer >= 200000001) answer = -1;
        System.out.println(answer);
    }

}
