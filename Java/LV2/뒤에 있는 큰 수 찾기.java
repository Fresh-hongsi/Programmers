import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        
        Stack<Integer> st = new Stack<Integer>();
        
        for(int i=numbers.length-1;i>=0;i--){
            
            while(true){
                if(st.empty()){
                    st.add(numbers[i]);
                    answer[i]=-1;
                    break;
                }   
                
                else{
                    if(numbers[i]<st.peek()){
                        answer[i]=st.peek();
                        st.add(numbers[i]);
                        break;
                    }
                    
                    else{
                        st.pop();
                    }
                }
            }
        }
        
        return answer;
    }
}
