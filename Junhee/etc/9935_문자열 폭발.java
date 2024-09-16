import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Bomb {
    static String s;
    static String bomb;
    static Stack<Character> s_list = new Stack<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        s = br.readLine();
        bomb = br.readLine();
        for(int i = 0; i < s.length(); i++) {
            s_list.add(s.charAt(i));
            boolean flag = true;
            if(s_list.size() >= bomb.length()) {
                for(int j = 0; j < bomb.length(); j++) {
                    if(s_list.get(s_list.size() - bomb.length() + j) != bomb.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int j = 0; j < bomb.length(); j++) {
                        s_list.remove(s_list.size() - 1);
                    }
                }
            }
        }

        if(s_list.size() == 0) System.out.println("FRULA");
        else {
            for (char c : s_list) {
                sb.append(c);
            }
            System.out.println(sb);
        }
    }
}
