import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<works.length;i++){
            pq.add(works[i]);
        }
        
        while(true){
            int top = pq.peek();
            if(top==0 || n==0){
                break;
            }
            
            else{
                n--;
                top-=1;
                pq.poll();
                pq.add(top);
            }
        }
        
        while(!pq.isEmpty()){
            answer+=(int)Math.pow(pq.peek(),2);
            pq.poll();
        }
        return answer;
    }
}
