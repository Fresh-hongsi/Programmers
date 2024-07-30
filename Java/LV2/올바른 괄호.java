import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> st = new Stack<>();
        
        for(int i=0;i<s.length();i++){
            
            if(s.charAt(i)=='('){
                st.push('(');    
            }
            
            else if(s.charAt(i)==')'){
                if(!st.isEmpty()){ // 비어있지 않다면
                    if(st.peek()=='('){
                        st.pop();
                    }
                    else{
                        st.push(')');
                    }
                }
                else{ // 비어있다면
                    st.push(')');
                }
            }
        }
        
        if(!st.isEmpty()){
            answer=false;
        }else{
            answer=true;
        }

        return answer;
    }
}
