import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static int[] ground;
    static int[] temp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ground = new int[n + 1];
        temp = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            ground[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int amount = Integer.parseInt(st.nextToken());
            temp[start - 1] += amount;
            temp[end] -= amount;
        }

        for(int i = 1; i < n; i++) {
            temp[i] += temp[i - 1];
        }

        for(int i = 0; i < n; i++) {
            ground[i] += temp[i];
        }

        for(int i = 0; i < n; i++) {
            System.out.print(ground[i] + " ");
        }
    }
}
