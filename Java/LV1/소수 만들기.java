import java.util.*;

class Solution {
    

    public boolean isPrime(int num){
        
        boolean flag = true;
        
        for(int i=2;i*i<=num;i++){
           if(num%i==0){
               flag=false;
               break;
           }     
        }
        
        return flag;
    }

    
    public int solution(int[] nums) {
        int answer = 0;

        for(int i=0;i<nums.length-2;i++){
            for(int j=i+1;j<nums.length-1;j++){
                for(int k=j+1;k<nums.length;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(isPrime(sum)){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
}
