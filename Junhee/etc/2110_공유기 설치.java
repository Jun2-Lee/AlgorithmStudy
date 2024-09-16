import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Wifi {
    static int n, c;
    static ArrayList<Integer> house_list = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++) {
            house_list.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(house_list);
        int start = 1;
        int end = house_list.get(house_list.size() - 1);
        int mid = -1;
        while(start <= end) {
            mid = (start + end) / 2;
            int cnt = 1;
            int idx = 0;
            //System.out.println("start : " + start + " end : " + end);
            //System.out.println(mid);
            for(int i = 1; i < house_list.size(); i++) {
                if(house_list.get(i) - house_list.get(idx) >= mid) {
                    //System.out.println(i + " " + idx);
                    cnt++;
                    idx = i;
                }
            }
            if(cnt >= c) {
                //System.out.println("flag : " + cnt);
                start = mid + 1;
            }
            else {
                //System.out.println("flag2 : " + cnt);
                end = mid - 1;
            }
        }
        System.out.println(end);
    }
}
