import java.util.*;


class Solution {
    
    public boolean calculate(int n){
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
            }
        }
        
        if(count%2==0){
            return true;
        }
        else{
            return false;
    
        }
    }
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int i=left;i<=right;i++){
            if(calculate(i)==true){
                answer+=i;
            }
            else{
                answer-=i;
            }
        }
        return answer;
    }
}
