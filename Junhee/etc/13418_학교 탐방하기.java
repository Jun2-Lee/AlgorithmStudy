import java.io.*;
import java.util.*;

class Node {
    int s, e, w;
    
    Node(int s, int e, int w) {
        this.s = s;
        this.e = e;
        this.w = w;
    }
}

public class test {
    static int n, m;
    static ArrayList<Node> list = new ArrayList<>();
    static int[] unf1, unf2;
    static int[] answer = new int[2];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        for (int i = 0; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            list.add(new Node(s, e, w));
        }
        
        unf1 = new int[n + 1];
        unf2 = new int[n + 1];
        
        for (int i = 0; i <= n; i++) {
            unf1[i] = i;
            unf2[i] = i;
        }
        
        list.sort((a, b) -> b.w - a.w);
        kruskal1();
        
        list.sort((a, b) -> a.w - b.w);
        kruskal2();
        
        System.out.println(answer[1] * answer[1] - answer[0] * answer[0]);
    }
    
    static int Find1(int a) {
        if (unf1[a] == a) return a;
        return unf1[a] = Find1(unf1[a]);
    }
    
    static void Union1(int a, int b) {
        int fa = Find1(a);
        int fb = Find1(b);
        if (fa != fb) {
            unf1[fa] = fb;
        }
    }
    
    static int Find2(int a) {
        if (unf2[a] == a) return a;
        return unf2[a] = Find2(unf2[a]);
    }
    
    static void Union2(int a, int b) {
        int fa = Find2(a);
        int fb = Find2(b);
        if (fa != fb) {
            unf2[fa] = fb;
        }
    }
    
    static void kruskal1() {
        for (Node node : list) {
            if (Find1(node.s) != Find1(node.e)) {
                Union1(node.s, node.e);
                if (node.w == 0) {
                    answer[0]++;
                }
            }
        }
    }
    
    static void kruskal2() {
        for (Node node : list) {
            if (Find2(node.s) != Find2(node.e)) {
                Union2(node.s, node.e);
                if (node.w == 0) {
                    answer[1]++;
                }
            }
        }
    }
}
