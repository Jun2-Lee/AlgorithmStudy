import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ3079 {

    static int N, M;
    static List<Long> times = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i = 0; i < N; i++) {
            times.add(Long.parseLong(br.readLine()));
        }
        Collections.sort(times);
        long start = 0;
        long end = times.get(times.size() - 1) * 1000000000;
        //System.out.println(end);
        while(start <= end) {
            long mid = (start + end) / 2;
            //System.out.println(mid);
            long cnt = 0;
            for(int i = 0; i < N; i++) {
                cnt += mid / times.get(i);
                if(cnt > M) break;
            }
            if(cnt >= M) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        System.out.println(start);
    }
}
