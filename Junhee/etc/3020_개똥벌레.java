import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ3020 {
    static int n, h;
    static int[] up;
    static int[] down;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        up = new int[n / 2];
        down = new int[n / 2];
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                down[i / 2] = Integer.parseInt(br.readLine());
            }
            else {
                up[i / 2] = Integer.parseInt(br.readLine());
            }
        }
        Arrays.sort(up);
        Arrays.sort(down);
        int min = Integer.MAX_VALUE;
        int answer = 0;
        for(int i = 1; i <= h; i++) {
            int cnt = 0;
            int start = 0;
            int end = n / 2;
            while(start < end) {
                int mid = (start + end) / 2;
                if(down[mid] >= i) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }
            cnt += (n/2 - end);
            //System.out.println("i = " + i + " , cnt = " + cnt);
            start = 0;
            end = n / 2;
            while(start < end) {
                int mid = (start + end) / 2;
                if(up[mid] >= h - i + 1) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }
            //System.out.println("================");
            cnt += (n/2 - end);
            //System.out.println("i = " + i + " , cnt = " + cnt);
            if(min == cnt) {
                answer++;
                continue;
            }
            if(min > cnt) {
                min = cnt;
                answer = 1;
            }
        }
        System.out.println(min + " " + answer);
    }
}
