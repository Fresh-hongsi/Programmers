import java.util.*;

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        
        for(int i=0;i<=t.length()-p.length();i++){
            String k = t.substring(i,i+p.length());
            
            //System.out.println(Integer.parseInt(k));
            if(Long.parseLong(k)<=Long.parseLong(p)){
                answer++;
            }
        }
       
        return answer;
    }
}
