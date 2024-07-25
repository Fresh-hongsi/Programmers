import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        for(int i=1000;i>=0;i--){
            int hIndex = i;
            int count = 0;
            for(int j=0;j<citations.length;j++){
                if(citations[j]>=hIndex){
                    count++;
                }
            }
            
            if(count>=hIndex){
                answer=hIndex;
                break;
            }
        }
        return answer;
    }
}
