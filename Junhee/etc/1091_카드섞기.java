import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1091 {
    static int N;
    static int[] P;
    static int[] S;
    static int[] first_card;
    static int[] cur_card;
    static void shuffle() {
        int[] temp = new int[N];
        for(int i = 0; i < N; i++) {
            temp[S[i]] = cur_card[i];
        }
        for(int i = 0; i < N; i++) {
            cur_card[i] = temp[i];
        }
    }

    static boolean check() {
        for(int i = 0; i < N; i++) {
            if(P[cur_card[i]] != i % 3)
                return false;
        }
        return true;
    }
    static boolean is_possible() {
        for(int i = 0; i < N; i++) {
            if(cur_card[i] != first_card[i])
                return false;
        }
        return true;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        P = new int[N];
        S = new int[N];
        first_card = new int[N];
        cur_card = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < N; i++) {
            first_card[i] = i;
            cur_card[i] = i;
        }
        int cnt = 0;
        
        while(true) {
            if(check()) {
                //System.out.println("correct");
                break;
            }
            shuffle();
            cnt++;
            if(is_possible()) {
                cnt = -1;
                break;
            }
            //System.out.println(1);
        }
        System.out.println(cnt);
    }
}
