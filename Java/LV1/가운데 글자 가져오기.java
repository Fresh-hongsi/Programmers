import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        if(s.length()%2==0){
            char a = s.charAt(s.length()/2-1);
            char b = s.charAt(s.length()/2);
            answer+=a;
            answer+=b;
        }
        else{
            char a = s.charAt(s.length()/2);
            answer+=a;
            
        }
        
        
        return answer;
    }
}
