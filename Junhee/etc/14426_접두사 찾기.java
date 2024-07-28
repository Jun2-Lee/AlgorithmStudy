import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        Set<String> s = new HashSet<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n, m;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String temp;
            temp = br.readLine();
            for (int j = 1; j <= temp.length(); j++){
                String sub_s = temp.substring(0, j);
                s.add(sub_s);
            }
        }
        int answer = 0;
        for (int i = 0; i < m; i++) {
            String temp = br.readLine();
            if(s.contains(temp)) answer++;
        }

        System.out.println(answer);


    }
}
