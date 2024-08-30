import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        
        Arrays.sort(stations);
        int startIndex = 1;
        int size = w+w+1;
        for(int i=0;i<stations.length;i++){
            int k = stations[i];
            
            if(k-w-startIndex>0){
                if((k-w-startIndex)%size==0){
                    answer+=(k-w-startIndex)/size;
                }
                else{
                    answer+=(k-w-startIndex)/size+1;
                }
            }
            startIndex=k+w+1;
        }
        
        if(n-startIndex>=0){
            if((n-startIndex+1)%size==0){
                answer+=(n-startIndex+1)/size;
            }
            else{
                answer+=(n-startIndex+1)/size+1;
            }
        }
        

        return answer;
    }
}
