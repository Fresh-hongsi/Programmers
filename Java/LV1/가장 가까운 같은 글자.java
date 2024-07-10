import java.util.*;

class Solution {
    public int[] solution(String s) {
        
        HashMap<Character,Integer> hm = new HashMap<Character,Integer>();
         int[] answer = new int[s.length()];
        for(int i=0;i<s.length();i++){
            char cur = s.charAt(i);
            int value= 0;
            if(hm.containsKey(cur)){ // 이미 있다면
                value=i-hm.get(cur);
                hm.put(cur,i);
                
            }
            else{ // 없다면
                hm.put(cur,i);
                value=-1;
            }
            
            answer[i]=value;
        }
       
        return answer;
    }
}
