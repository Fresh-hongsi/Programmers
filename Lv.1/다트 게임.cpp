#include <string>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    string temp = "";
    stack<int> st;
    
    for(int i=0;i<dartResult.length();i++){
        
        // 숫자가 들어온 경우 -> temp 문자열로 추적
        if(dartResult[i]>='0' && dartResult[i]<='9'){ 
            temp+=dartResult[i];
        }
        
        // 문자 또는 이벤트가 들어온 경우
        else{
            
            // S 점수 계산 후 스택에 넣기
            if(dartResult[i]=='S'){
                
                int cur = stoi(temp);
                temp="";
                cur = pow(cur,1);
                st.push(cur);
                
            }
            
            // D 점수 계산 후 스택에 넣기
            if(dartResult[i]=='D'){
                
                int cur = stoi(temp);
                temp="";
                cur = pow(cur,2);
                st.push(cur);
                
            }
            
            // T 계산 후 스택에 넣기
            if(dartResult[i]=='T'){
                
                int cur = stoi(temp);
                temp="";
                cur = pow(cur,3);
                st.push(cur);
                
            }
            
            // * 연산의 경우
            if(dartResult[i]=='*'){
                // 현재 스택에 1개 있는 경우 하나만 POP 하고 계산 후에 다시 PUSH
                if(st.size()==1){
                    
                    int a = st.top();
                    st.pop();
                    a*=2;
                    st.push(a);
                    
                }
                // 스택에 두개 있는 경우, 둘 다 POP해서 계산 후, 순서에 맞게 다시 넣어줘야한다
                else{
                    int a = st.top();
                    st.pop();
                    int b= st.top();
                    st.pop();
                    
                    a*=2;
                    b*=2;
                    st.push(b);
                    st.push(a);
                }

            }
            
            // # 연산의 경우
            if(dartResult[i]=='#'){
                
                // 현재 거  pop하고 다시 세팅 후 둘 다 push
                int a = st.top();
                st.pop();
                    
                a*=-1;
                st.push(a);
            }
                
            
            
        }
        
    }
    
    // 스택에 있는 모든 값들 더하기
    while(!st.empty()){
        answer+=st.top();
        st.pop();
    }
    return answer;
}






