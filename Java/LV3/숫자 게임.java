import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        
        Queue<Integer> aQ = new LinkedList<Integer>();
        Queue<Integer> bQ = new LinkedList<Integer>();
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int i=0;i<A.length;i++){
            aQ.add(A[i]);
            bQ.add(B[i]);
        }
         
        while(!aQ.isEmpty() && !bQ.isEmpty()){
            int aFront = aQ.peek();
            int bFront = bQ.peek();
            aQ.poll();
            bQ.poll();
            
            if(aFront<bFront){
                answer++;
            }
            
            else{
                ArrayList<Integer> temp = new ArrayList<Integer>();
                while(!bQ.isEmpty()){
                    int newFront = bQ.peek();
                    bQ.poll();
                    
                    if(newFront>aFront){
                        answer++;
                        break;
                    }
                    else{
                        temp.add(bFront);
                    }
                }
                
                for(int i=0;i<temp.size();i++){
                    bQ.add(temp.get(i));
                }
            }
        }
        return answer;
    }
}
