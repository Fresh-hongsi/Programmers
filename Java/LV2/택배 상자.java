import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        
        Queue<Integer> mainQ = new LinkedList<Integer>();
        Stack<Integer> subBelt = new Stack<Integer>();
        
        for(int i=1;i<=order.length;i++){
            mainQ.add(i);
        }
        
        for(int i=0;i<order.length;i++){
            int curTarget = order[i];
            
            if(!subBelt.isEmpty()){
                if(curTarget == subBelt.peek()){
                    subBelt.pop();
                    answer++;
                    continue;
                }
            }
            
            boolean flag = false;
            while(!mainQ.isEmpty()){
                flag = false;
                int mainQFront = mainQ.peek();
                mainQ.poll();
                
                if(mainQFront == curTarget){
                    answer++;
                    flag=true;
                    break;
                }
                else{
                    subBelt.push(mainQFront);
                }
                
            }
            
            if(flag==true){
                continue;
            }
            if(mainQ.isEmpty()){
                break;
            }
        }
        return answer;
    }
}
