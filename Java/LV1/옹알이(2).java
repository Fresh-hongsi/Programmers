import java.util.*;

class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        
        for(int i=0;i<babbling.length;i++){
            babbling[i] = babbling[i].replace("aya","1");
            babbling[i] = babbling[i].replace("ye","2");
            babbling[i] = babbling[i].replace("woo","3");
            babbling[i] = babbling[i].replace("ma","4");
        }
        
        for(String k : babbling){
            boolean flag = true;
            
            
            for(int i=0;i<k.length();i++){
                if(k.charAt(i)<'1' || k.charAt(i)>'4'){
                    flag=false;
                    break;
                }
            }
            
            for(int i=1;i<k.length();i++){
                if(k.charAt(i-1)==k.charAt(i)){
                    flag=false;
                    break;
                }
            }
            
            if(flag==true){
                answer++;
            }
        }
        
        return answer;
    }
}
