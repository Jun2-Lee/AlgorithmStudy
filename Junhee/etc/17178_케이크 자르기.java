import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Cake {
    static int n, m, l;
    static int[] cake;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        cake = new int[m + 1];
        for(int i = 0; i < m; i++) {
            cake[i] = Integer.parseInt(br.readLine());
        }
        cake[m] = l;
        for(int i = 0; i < n; i++) {
            int count = Integer.parseInt(br.readLine());
            int start = 0;
            int end = l;
            int min = -1;
            while(start <= end) {
                int mid = (start + end) / 2;
                int cnt = 0;
                int prev = 0;
                for(int j = 0; j < m + 1; j++) {
                    if(cake[j] - prev >= mid) {
                        cnt++;
                        prev = cake[j];
                    }
                }
                if(cnt > count) {
                    min = Math.max(min, mid);
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            System.out.println(min);
        }
    }
}
