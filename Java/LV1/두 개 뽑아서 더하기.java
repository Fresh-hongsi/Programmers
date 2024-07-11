import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        HashSet<Integer> hs = new HashSet<Integer>();
        
        for(int i=0;i<numbers.length-1;i++){
            for(int j=i+1;j<numbers.length;j++){
                int num = numbers[i]+numbers[j];
                hs.add(num);
            }
        }
        int[] answer = new int[hs.size()];
        int idx = 0;
        for(Integer k : hs){
            answer[idx++]=k;
        }
        
        Arrays.sort(answer);
        return answer;
    }
}
