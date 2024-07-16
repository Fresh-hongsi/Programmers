#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    // 역순으로 돌아가보기
    for(int i=numbers.size()-1;i>=0;i--){
        
        while(1){
            
            // 스택이 비어있다면
            if(st.empty()){
                answer.push_back(-1); // 더 큰 수가 없다는 것이므로 -1을 answer에 추가
                st.push(numbers[i]); // 현재 값을 스택에 넣어주기
                break;
            }
        
            else{ // 스택에 뭐가 들어있다면 비교해보기
                if(numbers[i]<st.top()){ // 만약 현재 수가 스택에 들어있는 수보다 작다면 뒷 큰수가 있다는 것!
                    answer.push_back(st.top()); // 뒷 큰수를 answer에 추가
                    st.push(numbers[i]); // 현재 수를 스택에 추가
                    break;
                }
                else{ // 만약 현재 수가 스택에 들어있는 수보다 크거나 같다면 스택에 남은 뒷큰 수 더 찾아보기 위해 top제거하기
                    st.pop();
                }
                      
            }
            
        }
    }
    
    reverse(answer.begin(),answer.end()); // answer의 역순이 정답임!
    
    return answer;
}



