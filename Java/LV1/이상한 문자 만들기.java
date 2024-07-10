import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        int counter = 0;
        
        for(int i=0;i<s.length();i++){
            
            if(s.charAt(i)==' '){
                counter=0;
                answer+=" ";
                continue;
            }
            
            if(counter%2==0){
                String k = s.toUpperCase();
                answer+=k.charAt(i);
                counter++;
            }    
            
            else{
                String k = s.toLowerCase();
                answer+=k.charAt(i);
                counter++;
            }
        }
        return answer;
    }
}
