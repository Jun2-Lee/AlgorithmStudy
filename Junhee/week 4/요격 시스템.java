import java.util.Arrays;
import java.util.Comparator;
class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, Comparator.comparingInt((int[] o) -> o[1]));
        int end = targets[0][1];
        answer++;
        for(int[] tar : targets){
            if(tar[0] >= end){
                end = tar[1];
                answer++;
            }
        }
        return answer;
    }
}
