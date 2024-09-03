import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        
        int start = 0;
        int end = 0;
        int resStart = 0;
        int resEnd = 0;
        int sum = sequence[0];
        int min = 99999999;
        
        while((start<sequence.length) && (end<sequence.length)){
            
            if(sum==k){
                if(end-start<min){
                    min = end-start;
                    resStart = start;
                    resEnd = end;
                }
                
                end++;
                if(end==sequence.length){
                    continue;
                }
                sum+=sequence[end];
            }
            
            else if(sum<k){
                end++;
                if(end==sequence.length){
                    continue;
                }
                sum+=sequence[end];
            }
            else{
                sum-=sequence[start];
                start++;
            }
        }
        
        answer[0]=resStart;
        answer[1]=resEnd;
        
        return answer;
    }
}
