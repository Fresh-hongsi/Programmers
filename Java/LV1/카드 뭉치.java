import java.util.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        
        Deque<String> dq1 = new LinkedList<>();
        Deque<String> dq2 = new LinkedList<>();
        Deque<String> dq3 = new LinkedList<>();
        
        for(int i=0;i<cards1.length;i++){
            dq1.addLast(cards1[i]);
        }
        
        for(int i=0;i<cards2.length;i++){
            dq2.addLast(cards2[i]);
        }
        
        for(int i=0;i<goal.length;i++){
            dq3.addLast(goal[i]);
        }
        
        
        while(true){
            
            if(dq3.isEmpty()){
                answer = "Yes";
                break;
            }
            
            
            String c1 = "";
            String c2 = "";
            String c3 = "";
            
            if(!dq1.isEmpty()){
                c1 = dq1.getFirst();
            }
            
            if(!dq2.isEmpty()){
                c2 = dq2.getFirst();
            }
            
            if(!dq3.isEmpty()){
                c3=dq3.getFirst();
            }
            
            
            

            if(c1.equals(c3)){
                dq1.removeFirst();
                dq3.removeFirst();
            }
            else if(c2.equals(c3)){
                dq2.removeFirst();
                dq3.removeFirst();
            }
            else{
                answer = "No";
                break;
            }
        }
        return answer;
    }
}
