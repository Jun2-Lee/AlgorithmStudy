import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes, Comparator.comparingInt((int[] o) -> o[1]));
        int end = routes[0][1];
        answer++;
        for(int[] route : routes) {
            if(route[0] > end) {
                answer++;
                end = route[1];
            }
        }
        return answer;
    }
}
