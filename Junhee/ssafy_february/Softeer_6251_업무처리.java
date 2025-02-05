import java.io.*;
import java.util.*;

public class Main {

    static int h, k, r;
    static int res = 0;
    static int day = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        h = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        int num = (int) Math.pow(2, h + 1);
        ArrayDeque<Integer>[][] people = new ArrayDeque[num][2];
        
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < 2; j++) {
                people[i][j] = new ArrayDeque<>();
            }
        }

        int leafIdx = (int) Math.pow(2, h);
        for (int i = leafIdx; i < num; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < k; j++) {
                people[i][0].add(Integer.parseInt(st.nextToken()));
            }
        }

        while (day++ < r) {
            update(people, leafIdx, num);
        }

        while (!people[0][0].isEmpty()) {
            res += people[0][0].poll();
        }
        while (!people[0][1].isEmpty()) {
            res += people[0][1].poll();
        }

        System.out.println(res);
    }

    static void update(ArrayDeque<Integer>[][] people, int leafIdx, int num) {
        for (int i = 1; i < num; i++) {
            if (i < leafIdx) {
                if (day % 2 == 1) {
                    work(people, i, false);
                } else {
                    work(people, i, true);
                }
            } else {
                work(people, i, false);
            }
        }
    }

    static void work(ArrayDeque<Integer>[][] people, int i, boolean isEven) {
        if (isEven) {
            if (!people[i][1].isEmpty()) {
                int w = people[i][1].poll();
                if (i % 2 == 1) people[i / 2][1].add(w);
                else people[i / 2][0].add(w);
            }
        } else {
            if (!people[i][0].isEmpty()) {
                int w = people[i][0].poll();
                if (i % 2 == 1) people[i / 2][1].add(w);
                else people[i / 2][0].add(w);
            }
        }
    }
}
