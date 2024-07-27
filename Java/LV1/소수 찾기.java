import java.util.*;
class Solution {
    public int solution(int n) {
        int answer = 0;
        
        boolean[] arr = new boolean[n+1];
        for(int i=0;i<arr.length;i++){
            arr[i]=true;
        }
        arr[0]=false; // 소수 아님
        arr[1]=false; // 소수 아님
        
        for(int i=2;i*i<=n;i++){
            if(arr[i]==true){
                for(int j=i+i;j<=n;j+=i){
                    arr[j]=false;
                }
            }
  
        }
        
        for(int i=1;i<=n;i++){
            if(arr[i]==true){
                answer++;
            }
        }
        return answer;
    }
}
