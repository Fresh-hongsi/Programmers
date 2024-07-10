import java.util.*;

class Solution {
    

    public int encrypt(int num){
        String k = "";
        
        while(num!=0){
            k+=Integer.toString(num%3);
            num/=3;
        }
        
        System.out.println(k);
        return Integer.parseInt(k);
    }
    
    public int decrypt(int num){
        String k = Integer.toString(num);
        int prefix = 1;
        int answer = 0;
        for(int i=k.length()-1;i>=0;i--){
            answer+=prefix*(k.charAt(i)-'0');
            prefix*=3;
        }
        
        return answer;
    }
    
    public int solution(int n) {
        int answer = 0;
        
        int a = encrypt(n);
        int b = decrypt(a);
        answer=b;
        return answer;
    }
}
