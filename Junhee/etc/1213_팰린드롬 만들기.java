import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] alpha = new int [26];
    static int oddIdx = -1;
    static boolean checkPalindrome() {
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(alpha[i] % 2 == 1) {
                cnt++;
                oddIdx = i;
            }
            if(cnt > 1) return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        for(int i = 0; i < input.length(); i++) {
            alpha[(int)input.charAt(i) - 'A'] += 1;
        }
        if(!checkPalindrome()) {
            System.out.println("I'm Sorry Hansoo");
            return;
        }
        String answer = "";
        String back = "";
        for(int i = 0; i < 26; i++) {
            if(alpha[i] != 0) {
                for(int j = 0; j < alpha[i] / 2; j++) {
                    answer += (char)(i + 'A');
                }
            }
        }
        for(int i = answer.length() - 1; i >= 0; i--) {
            back += answer.charAt(i);
        }
        if(oddIdx != -1) {
            answer += (char)(oddIdx + 'A');
        }
        answer += back;

        System.out.println(answer);
    }
}
