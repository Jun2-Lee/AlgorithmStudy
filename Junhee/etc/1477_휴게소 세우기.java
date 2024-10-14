import java.util.*;
import java.io.*;
public class BOJ1477 {
    static int n, m, l;
    static int[] rest_area;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        rest_area = new int[n + 2];
        rest_area[0] = 0;
        rest_area[n + 1] = l;
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) {
            rest_area[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(rest_area);
        int max_len = 0;
        int start = 1;
        int end = l - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            int cnt = 0;
            for(int i = 0; i < n + 1; i++) {
                int len = rest_area[i + 1] - rest_area[i];
                cnt += (len - 1) / mid; 
            }
            //System.out.println(cnt + "--");
            if(m < cnt) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            //System.out.println(mid);
        }

        System.out.println(start);
    }
}
