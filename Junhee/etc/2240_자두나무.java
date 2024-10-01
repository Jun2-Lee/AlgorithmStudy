import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Tree {
    static int t, w;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        dp = new int[t + 1][w + 1];

        for(int i = 1; i <= t; i++) {
            int plum = Integer.parseInt(br.readLine());
            if(plum == 1) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
            for(int j = 1; j <= w; j++) {
                if(j % 2 == 1) {
                    if(plum == 2) {
                        dp[i][j] = Math.max(dp[i - 1][j] + 1, dp[i - 1][j - 1]);
                    }
                    else {
                        dp[i][j] = Math.max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
                    }
                }
                else {
                    if(plum == 1) {
                        dp[i][j] = Math.max(dp[i - 1][j] + 1, dp[i - 1][j - 1]);
                    }
                    else {
                        dp[i][j] = Math.max(dp[i -1][j - 1] + 1, dp[i - 1][j]);
                    }
                }
            }
        }
        int answer = 0;

        for(int i = 0; i <= w; i++) {
            answer = Math.max(answer, dp[t][i]);
        }

        System.out.println(answer);
    }
}
