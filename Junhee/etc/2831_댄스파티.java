
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2831 {
    static int N;
    static int[] man;
    static int[] woman;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        man = new int[N];
        woman = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            man[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            woman[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(man);
        Arrays.sort(woman);
        int start = 0;
        int end = N - 1;
        int answer = 0;
        while (true) {
            if (start >= N || end < 0)
                break;
            if (man[start] < 0) {
                if (woman[end] < 0) {
                    start++;
                    continue;
                }
                if (woman[end] > 0 && (-1 * man[start]) > woman[end]) {
                    answer++;
                    start++;
                    end--;
                } else {
                    end--;
                }
            } else {
                if (woman[end] < 0 && man[start] < (-1 * woman[end])) {
                    answer++;
                    start++;
                    end--;
                } else {
                    end--;
                }
            }
            
        }
        System.out.println(answer);
    }
}
