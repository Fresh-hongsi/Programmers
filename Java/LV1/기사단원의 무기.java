import java.util.*;

class Solution {
    
    public int numOfYaksu(int num){
        int r = 0;
        
        for(int i=1;i<=Math.sqrt(num);i++){
            if(num%i==0){
                if(num/i==i){
                    r++;
                }else{
                    r+=2;
                }
            }
        }
        
        return r;
    }
    
    public int solution(int number, int limit, int power) {
        
        int answer = 0;
        for(int i=1;i<=number;i++){
            int k = numOfYaksu(i);
            if(k>limit){
                k=power;
            }
            //System.out.println(k);
            answer+=k;
        }
        
        return answer;
    }
}
