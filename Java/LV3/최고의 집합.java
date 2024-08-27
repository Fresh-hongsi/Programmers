import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        int[] answer = {};
        
        if(s/n<1){
            answer = new int[1];
            answer[0]=-1;
        }
        
        else{
            int partition = s/n;
            int remainder = s%n;
            int counter = 0;
            answer = new int[n];
            for(int i=0;i<remainder;i++){
                answer[i]=partition+1;
                counter++;
            }
            
            for(int i=counter;i<n;i++){
                answer[i]=partition;
            }
        }
        
        Arrays.sort(answer);
        return answer;
    }
}
