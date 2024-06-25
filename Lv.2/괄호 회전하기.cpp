// #include <string>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// bool checkValid(queue<char> tempQ){ // 해당 회전된 문자열이 올바른 괄호인지 판단하는 함수
//     stack<char> st;
//     bool flag = false;

//     int length = tempQ.size();
//     for(int i = 0; i<length;i++){
//         char cur = tempQ.front();
        
//         tempQ.pop();
//         if(cur == '(' || cur == '{' || cur=='[' ){
//             st.push(cur);
//         }
//         else if(cur == ')'){
//             if(!st.empty()){
//                 if(st.top()=='('){
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
//         else if(cur == '}'){
//             if(!st.empty()){
//                 if(st.top()=='{'){
//                     st.pop();
//                 }
//                 else{
//                     st.push('}');
//                 }
//             }
//             else{
//                 st.push('}');
//             }
            
//         }
//         else if(cur == ']'){
//             if(!st.empty()){
//                 if(st.top()=='['){
//                     st.pop();
//                 }
//                 else{
//                     st.push(']');
//                 }
//             }
//             else{
//                 st.push(']');
//             }
//         }
//     }
//     if(st.empty()){
//         flag=true;
//     }
    
//     return flag;
// }


// int solution(string s) {
//     int answer = 0;
    
//     queue<char> q;
//     for(int i=0;i<s.length();i++){
//         q.push(s[i]);
//     }
    
//     // 하나씩 회전해보며 해당 문자열이 올바른 지 확인
//     for(int i=0;i<q.size();i++){
//         //cout<<q.front()<<' ';
//         bool isValid = checkValid(q);
//         char temp = q.front();
//         q.pop();
//         q.push(temp);
//         if(isValid==true){
//             answer+=1;
//         }
//     }
//     return answer;
// }


#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <iostream>
#include <deque>
using namespace std;

bool check(deque<char> dq){
    stack<char> st;
    
    for(int i=0;i<dq.size();i++){
        
        if(!st.empty()){
            char top = st.top();
            if(top=='[' && dq[i]==']'){
                st.pop();
            }
            
            else if(top=='(' && dq[i]==')'){
                st.pop();
            }
            
            else if(top=='{' && dq[i]=='}'){
                st.pop();
            }
            else{
                st.push(dq[i]);
            }
        }
        else{
            st.push(dq[i]);
        }
    }
    
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    
    for(int i=0;i<s.length();i++){
        dq.push_back(s[i]);
    }
    
    for(int i=0;i<s.length()-1;i++){
        

        bool flag = check(dq);
        if(flag==true){
           
            answer++;
        }
        
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
        

    }
    return answer;
}
