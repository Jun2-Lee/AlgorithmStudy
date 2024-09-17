import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Dragon {
    static long n, atk;
    static long t_atk;
    static long max_hp;
    static long cur_hp;
    static ArrayList<long[]> room = new ArrayList<>();

    static boolean fight(long m_atk, long m_hp) {
        long turn = 0;
        if(m_hp % t_atk == 0) turn = m_hp / t_atk;
        else turn = m_hp / t_atk + 1;
        //System.out.println("turn = " + turn + ", atk = " + m_atk + ", m_hp = " + m_hp);
        if(cur_hp - m_atk * (turn - 1) <= 0) {
            return false;
        }
        cur_hp -= m_atk * (turn - 1);
        return true;
    }
    static void heal(long p_atk, long hp) {
        cur_hp = Math.min(cur_hp + hp, max_hp);
        t_atk += p_atk;
    }
    static boolean play() {
        for(int i = 0; i < n; i++) {
            //System.out.println("before cur_hp = " + cur_hp);
            long[] cur = room.get(i);
            if(cur[0] == 1) {
                if(!fight(cur[1], cur[2])) {
                    return false;
                }
            }
            if(cur[0] == 2) {
                heal(cur[1], cur[2]);
            }
            //System.out.println("after cur_hp = " + cur_hp);
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        atk = Integer.parseInt(st.nextToken());
        long end = 0;
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long num = Long.parseLong(st.nextToken());
            long t_atk = Long.parseLong(st.nextToken());
            long t_hp = Long.parseLong(st.nextToken());
            room.add(new long[] {num, t_atk, t_hp});
            if(num == 1) {
                end += t_atk * t_hp;
            }
        }
        long start = 1;
        //System.out.println(end);
        long answer = 0;
        while(start <= end) {
            long mid = (start + end) / 2;
            max_hp = mid;
            cur_hp = mid;
            t_atk = atk;
            if(!play()) {
                //System.out.println("die");
                start = mid + 1;
            }
            else {
                //System.out.println("alive");
                end = mid - 1;
            }
            //System.out.println(mid);
        }
        System.out.println(start);
    }
}
