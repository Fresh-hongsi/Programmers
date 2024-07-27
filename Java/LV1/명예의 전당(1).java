import java.util.*;
class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0;i<score.length;i++){
            int curScore = score[i];
            if(pq.size()<k){
                pq.add(curScore);
            }
            else{
                int beforeTop = pq.peek();
                if(beforeTop<=curScore){
                    pq.poll();
                    pq.add(curScore);
                }
            }
            int top = pq.peek();
            answer[i]=top;
        }
        return answer;
    }
}
