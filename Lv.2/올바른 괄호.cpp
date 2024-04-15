#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char temp = s[i];
        if(temp=='('){
            st.push('(');
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                answer=false;
                break;
            }
        }
    }
    
    if(answer==true && !st.empty()){
        answer=false;
    }
    return answer;
}
