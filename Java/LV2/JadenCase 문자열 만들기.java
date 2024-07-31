import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
       
        for(int i=0;i<s.length();i++){
            
            if(i==0){
                answer+=Character.toString(Character.toUpperCase(s.charAt(i)));
            }
            
            else if(i>=1 && s.charAt(i-1)==' '){
                answer+=Character.toString(Character.toUpperCase(s.charAt(i)));
            }
            else{
                answer+=Character.toString(Character.toLowerCase(s.charAt(i)));
            }
        }
        
        return answer;
    }
}
