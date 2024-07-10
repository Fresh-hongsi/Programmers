import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int maxGaro=Math.max(sizes[0][0],sizes[0][1]);
        int maxSero=Math.min(sizes[0][0],sizes[0][1]);
        
        for(int i=0;i<sizes.length;i++){
            
            int garo = Math.max(sizes[i][0],sizes[i][1]);
            int sero = Math.min(sizes[i][0],sizes[i][1]);
            
            if(maxGaro<=garo){
                maxGaro=garo;
            }
            
            if(maxSero<=sero){
                maxSero=sero;
            }
        }
        answer=maxGaro*maxSero;
        return answer;
    }
}
