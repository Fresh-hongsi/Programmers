#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> st; // 바구니
    
    // 크레인 한번의 시행에 대해
    for(int i=0;i<moves.size();i++){
        
        int curCrane = moves[i]-1; // 현재 크레인 위치
        
        // 집을 인형 찾기
        for(int j=0;j<board.size();j++){
            
            // 만약 빈 공간이라면 한칸 다시 반복문 수행 -> 한 칸 아래로 내려가기 위함
            if(board[j][curCrane]==0){ 
                continue;
            }
            
            else{ // 해당 위치에서 인형을 발견한 경우
                st.push(board[j][curCrane]); // 바구니에 인형 넣기
                board[j][curCrane]=0; // 인형을 집었으므로 해당 위치에 인형 없애기
                
                // 만약 스택에 2개 이상 차있으면, 터질 인형이 있는 지 구하기
                if(st.size()>=2){
                    
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    
                    if(a==b){
                        answer+=2;
                    }
                    else{ // 안터졌으면 다시 스택에 인형 되돌려놓기
                        st.push(b);
                        st.push(a);
                    }
                }
                
                break;
            }
        }
    }
    return answer;
}


// 0 0 0 0 0    4 3 1 1 3 2  4
// 0 0 1 0 3
// 0 2 5 0 1
// 4 2 4 4 2
// 3 5 1 3 1
