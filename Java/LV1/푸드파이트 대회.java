import java.util.*;

class Solution {
    public String solution(int[] food) {
        String answer = "";
        
        for(int i=1;i<food.length;i++){
            int cur = food[i];
            
            for(int j=0;j<cur/2;j++){
                answer+=Integer.toString(i);
            }
        }
        StringBuffer sb = new StringBuffer(answer);
        String reverse = sb.reverse().toString();
        answer+="0";
        answer+=reverse;
        
        return answer;
    }
}
