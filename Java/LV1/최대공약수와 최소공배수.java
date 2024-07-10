import java.util.*;

class Solution {
    
    public int getGCD(int a, int b){
        if(b==0){
            return a;
        }
        
        else{
            return getGCD(b, a%b);
        }
    }
    
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        int max = Math.max(n,m);
        int min = Math.min(n,m);
        
        int gcd = getGCD(max,min);
        answer[0]=gcd;
        answer[1]=n*m/gcd;
        
        return answer;
    }
}
