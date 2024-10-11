
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2560 {
    static int a, b, d, N;
    static int[] dp = new int[1000001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < a; i++) {
            dp[i] = 1;
        }
        for (int i = a; i < N + 1; i++) {
            dp[i] = dp[i - 1] % 1000 + dp[i - a] % 1000;
            if (i >= b)
                dp[i] = (dp[i] - dp[i - b] + 1000) % 1000;
            // if (i >= d)
            //     dp[i] -= dp[i - d] % 1000;
            //dp[i] %= 1000;
        }
        if(N >= d) 
            System.out.println((dp[N] - dp[N - d] + 1000) % 1000);
        else
            System.out.println(dp[N] % 1000);
    }
}
