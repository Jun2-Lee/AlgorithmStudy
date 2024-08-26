import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Chicken {
    static int n;
    static int k;
    static int[] c_list;
    static int[] temp;
    static void merge_sort(int start, int len) {
        temp = new int[len];
        for(int i = 0; i < len; i++) {
            temp[i] = c_list[start + i];
        }
        Arrays.sort(temp);
        for(int i = 0; i < len; i++) {
            c_list[start + i] = temp[i];
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        c_list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            c_list[i] = Integer.parseInt(st.nextToken());
        }
        k = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i += n / k) {
            merge_sort(i, n / k);
        }
        for (int c : c_list) {
            sb.append(c).append(" ");
        }
        System.out.println(sb.toString());
    }
}
