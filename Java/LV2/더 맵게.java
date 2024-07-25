import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        boolean flag = false;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0;i<scoville.length;i++){
            pq.add(scoville[i]);
        }
        
        while(!pq.isEmpty()){
            Integer top = pq.peek();
            pq.poll();
            
            if(top>=K){
                flag = true;
                break;
            }else{
                if(pq.size()>=1){
                    
                    Integer second = pq.peek();
                    pq.poll();
                
                    Integer next = top+(2*second);
                    pq.add(next);
                    answer++;                    
                }
                
            }
            
        }
        
        if(flag==false){
            answer=-1;
        }
        
    
        return answer;
    }
}
