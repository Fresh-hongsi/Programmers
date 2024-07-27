import java.util.*;
class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        //3322111
        Integer[] sc = new Integer[score.length];
        
        for(int i=0;i<sc.length;i++){
            sc[i]=score[i];
        }
        
        Arrays.sort(sc,Collections.reverseOrder());
        int idx = m-1;
        while(idx<score.length){
            answer += sc[idx]*m;
            idx+=m;
        }
        return answer;
    }
}
//1112233
// 1: 2
// 2: 4
// 4: 6
// 112 222 444 444
// 3 6 12 12
