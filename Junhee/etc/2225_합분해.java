import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int K = scanner.nextInt();

        final int MOD = 1_000_000_000;

        long[][] d = new long[K + 1][N + 1];

        d[0][0] = 1;

        for (int i = 1; i <= K; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= j; k++) {
                    d[i][j] += d[i - 1][j - k];
                    d[i][j] %= MOD;
                }
            }
        }

        System.out.println(d[K][N]);

    }
}
