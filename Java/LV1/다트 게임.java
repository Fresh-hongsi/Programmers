import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        String temp = "";
        Stack<Integer> st = new Stack<>();
        
        for(int i=0;i<dartResult.length();i++){
            
            // 점수일 경우
            if(dartResult.charAt(i)>='0' && dartResult.charAt(i)<='9'){
                temp+=Character.toString(dartResult.charAt(i));
            }
            
            // 보너스
            if(dartResult.charAt(i)=='S'){
                Integer k = Integer.parseInt(temp);
                k = (int)(Math.pow(k,1));
                st.push(k);
                temp="";
            }
            
            // 보너스
            if(dartResult.charAt(i)=='D'){
                Integer k = Integer.parseInt(temp);
                k = (int)(Math.pow(k,2));
                st.push(k);
                temp="";
            }
            
            // 보너스
            if(dartResult.charAt(i)=='T'){
                Integer k = Integer.parseInt(temp);
                k = (int)(Math.pow(k,3));
                st.push(k);
                temp="";
            }
            
            // 옵션 - 스타상
            if(dartResult.charAt(i)=='*'){
                if(st.size()==1){
                    int a = st.peek();
                    st.pop();
                    a*=2;
                    st.push(a);
                }
                
                if(st.size()==2 || st.size()==3){
                    int a = st.peek();
                    st.pop();
                    int b = st.peek();
                    st.pop();
                    a*=2;
                    b*=2;
                    
                    st.push(b);
                    st.push(a);
                }
                
            }
            
            // 옵션
            if(dartResult.charAt(i)=='#'){
                int a = st.peek();
                st.pop();
                a*=-1;
                st.push(a);
            }
        }
        
        while(!st.isEmpty()){
            int k = st.peek();
            //System.out.println(k);
            st.pop();
            answer+=k;
        }
        return answer;
    }
}
