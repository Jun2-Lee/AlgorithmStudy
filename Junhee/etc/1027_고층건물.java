import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Building {
    static int n;
    static int[] building = new int[50];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            building[i] = Integer.parseInt(st.nextToken());
        }
        int answer = 0;
        for(int idx = 0; idx < n; idx++) {
            double max_inclination = 0;
            int cnt = 0;
            for(int i = idx + 1; i < n; i++) {
                double t_inclination = (double) (building[idx] - building[i]) / (idx - i);
                if(max_inclination < t_inclination || i == idx + 1) {
                    cnt++;
                    max_inclination = t_inclination;
                }
            }
            //System.out.print("idx = " + idx + " " + cnt + " ");
            for(int i = idx - 1; i >= 0; i--) {
                double t_inclination = (double) (building[idx] - building[i]) / (idx - i);
                if(max_inclination > t_inclination || i == idx - 1) {
                    cnt++;
                    max_inclination = t_inclination;
                }
            }
            //System.out.println(cnt);
            answer = Math.max(answer, cnt);
            //System.out.println(idx + " " + answer);
        }
        System.out.println(answer);
    }
}
