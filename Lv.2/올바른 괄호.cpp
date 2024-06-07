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


// #include <string>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <stack>
// #include <functional>

// using namespace std;

// bool solution(string s)
// {
//     bool answer = true;

//     stack<char> st;
    
//     for(int i=0;i<s.length();i++){
//         char cur = s[i];
        
//         if(cur=='('){
//             st.push(cur);
//         }
//         else{
//             if(!st.empty()){
//               char top = st.top();
//                 if(top=='('){
//                     st.pop();
//                 }
//                 else{
//                     st.push(')');
//                 }  
//             }
//             else{
//                 st.push(')');
//             }
            
//         }
//     }
    
//     if(!st.empty()){
//         answer=false;
//     }
//     else{
//         answer=true;
//     }

//     return answer;
// }
