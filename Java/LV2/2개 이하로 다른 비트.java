import java.util.*;

class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        
        for(int i=0;i<numbers.length;i++){
            long cur = numbers[i];
            
            // 짝수일 경우
            if(cur%2==0){
                long result = cur+1;
                answer[i]=result;
            }
            
            // 홀수일 경우
            else{
                long base = 1;
                while((base|cur) == cur){
                    base*=2;
                }
                
                long result = cur+base;
                result-=(base/2);
                answer[i]=result;
            }
        }
        return answer;
    }
}
