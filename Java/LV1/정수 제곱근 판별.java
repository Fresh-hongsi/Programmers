import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        
        if((Math.pow((int)Math.sqrt(n),2)==n)){
            answer = (long)Math.pow((long)Math.sqrt(n)+1,2);
        }
        else{
            answer=-1;
        }
      
        return answer;
    }
}
