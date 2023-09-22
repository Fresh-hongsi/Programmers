#include<string>
#include <iostream>
#include <stack> // stack 사용
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<int> st;
    
    for(int i=0;i<s.length();i++) { // 문자열을 순회
        
        if(s[i]=='(') { // 만약 '(' 이 있다면 무조건 스택에 넣어주기
            st.push('(');
        }
        
        else if(s[i]==')') // 만약 ')' 이 나왔다면, 스택의 top에 '(' 이 있는지 확인하고, 있다면, top을 pop해주기
        {
            if(!st.empty() && st.top()=='(') // 스택이 비지 않고, top이 '(' 일때만 적용
            {
                st.pop();
                continue; 
            }
            
            else { // 그 외의 경우 ')'을 넣어줌
                st.push(')');
            }
        }
    }
    
    // 스택이 비지 않았다면, 올바르지 않은 괄호 표기법
    if (!st.empty()) {
        answer=false;
    }
    else {
        answer=true;
    }


    return answer;
}
