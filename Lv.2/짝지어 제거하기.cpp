// #include <iostream>
// #include <string>
// #include <stack> // 스택 활용
// using namespace std;

// int solution(string s)
// {
//     int answer = -1; // 답안 초기값은 -1로 세팅

//     stack<char> st; // 스택 생성
//     st.push(s[0]);  // 초기 스택에 s[0]값을 넣어놓음
    
//     for(int i=1;i<s.length();i++) // 문자열 처음부터 순회
//     {
//         if(!st.empty()) // 스택에 값이 들어있는 경우
//         {
//             if(st.top()==s[i]) // 만약 top이 s[i]랑 같다면
//             {
//                 st.pop(); // 짝지은 수 제거
//             }
            
//             else // 만약 top값이 s[i]랑 다르다면
//             {
//                 st.push(s[i]); // s[i]를 스택에 삽입
//             }
//         }
        
//         else // 스택이 비워져있는 경우 s[i]값을 스택에 넣어줌
//         {
//             st.push(s[i]);
//         }
        
//     }
    
//     if(!st.empty()) // 최종적으로 스택에 값이 있으면 실패
//     {
//         answer=0;
//     }
//     else // 최종적으로 스택에 값이 없으면 성공
//     {
//         answer=1;
//     }
//     return answer;
// }

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <functional>
// #include <stack>
// using namespace std;

// int solution(string s)
// {
//     int answer = -1;

//     stack<char> st;
//     st.push(s[0]);
    
//     for(int i=1;i<s.length();i++){
//         if(st.empty()){
//             st.push(s[i]);
//         }
        
//         else{
//             char t = st.top();
//             if(t==s[i]){
//                 st.pop();
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//     }
    
//     if(!st.empty()){
//         answer=0;
//     }else{
//         answer=1;
//     }

//     return answer;
// }


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        
        if(!st.empty()){
            char top = st.top();
            if(top==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else{
            st.push(s[i]);
        }
        
    }
    
    if(!st.empty()){
        answer=0;
    }
    else{
        answer=1;
    }
    
    return answer;
}
