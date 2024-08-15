import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static ArrayList<ArrayList<Integer>> node = new ArrayList<>();
    static int[] island;
    static void bfs(int start, int num) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        island[start] = num;
        while(!q.isEmpty()) {
            int curr = q.poll();
            for(int i = 0; i < node.get(curr).size(); i++) {
                if(island[node.get(curr).get(i)] == 0) {
                    island[node.get(curr).get(i)] = num;
                    q.add(node.get(curr).get(i));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++) {
            node.add(new ArrayList<>());
        }
        island = new int[n];
        for(int i = 0; i < n - 2; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()) - 1;
            int end = Integer.parseInt(st.nextToken()) - 1;
            node.get(start).add(end);
            node.get(end).add(start);
        }
        int num = 1;
        for(int i = 0; i < n; i++) {
            if(island[i] == 0) {
                bfs(i, num++);
            }
        }

        int island1 = -1, island2 = -1;
        for(int i = 0; i < n; i++) {
            if(island[i] == 1) {
                island1 = i + 1;
            }
            else {
                island2 = i + 1;
                break;
            }
        }
        System.out.println(island1 + " " + island2);
    }
}
