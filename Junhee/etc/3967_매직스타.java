import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ3967 {
    static int[] answer = new int[12];
    static int[] star = new int[12];
    static boolean[] visit = new boolean[13];
    static boolean flag = false;
    static boolean calc() {
        int[] sum = new int[6];
        sum[0] = star[0] + star[2] + star[5] + star[7];
        sum[1] = star[1] + star[2] + star[3] + star[4];
        sum[2] = star[0] + star[3] + star[6] + star[10];
        sum[3] = star[1] + star[5] + star[8] + star[11];
        sum[4] = star[4] + star[6] + star[9] + star[11];
        sum[5] = star[7] + star[8] + star[9] + star[10];
        for(int i = 0; i < 6; i++) {
            if(sum[i] != 26) {
                return false;
            }
        }
        return true;
    }

    static void make_permutation(int idx) {
        if(flag) return;
        if(idx == 12) {
            if(calc()) {
                flag = true;
                for(int i = 0; i < 12; i++) {
                    answer[i] = star[i];
                }
            }
            return;
        }
        if(star[idx] != 0)
            make_permutation(idx + 1);
        else {
            for(int i = 1; i <= 12; i++) {
                if(visit[i]) continue;
                visit[i] = true;
                star[idx] = i;
                make_permutation(idx + 1);
                star[idx] = 0;
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] star_s = new String[5];
        int idx = 0;
        for(int i = 0; i < 5; i++) {
            String temp = br.readLine();
            star_s[i] = temp;
            for(int j = 0; j < 9; j++) {
                char t_c = temp.charAt(j);
                if(t_c == 'x') {
                    star[idx++] = 0;
                }
                else if('A' <= t_c && t_c <= 'L') {
                    star[idx++] = t_c - 'A' + 1;
                    visit[t_c - 'A' + 1] = true;
                }
            }
        }
        make_permutation(0);
        idx = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 9; j++) {
                if(star_s[i].charAt(j) == '.')
                    sb.append(".");
                else {
                    sb.append((char) ((answer[idx++] - 1) + 'A'));
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
