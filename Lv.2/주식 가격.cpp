#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
using namespace std;

// lv2 뒤에 있는 큰 수 찾기 문제와 비슷
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    
    for(int i=prices.size()-1;i>=0;i--){
        

        // 2 3 4 4 3 1   3,1 1,5
        // 5 4 2 1 1 0  
        
        while(1){
            
            if(st.empty()){
                answer.push_back(prices.size()-i-1);
                st.push(make_pair(prices[i],i));
                break;
            }
            else{
                int topVal = st.top().first;
                int topIdx = st.top().second;
                if(prices[i]>topVal){
                    st.push(make_pair(prices[i],i));
                    answer.push_back(topIdx-i);
                    break;
                }
                else{
                    st.pop();

                }
            }
            
        }
        
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}
