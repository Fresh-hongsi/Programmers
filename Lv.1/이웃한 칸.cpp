#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dr[4]={-1,0,1,0}; // 상우하좌 행 변위
    int dc[4]={0,1,0,-1}; // 상우하좌 열 변위
    
    string targetColor = board[h][w];
    
    for(int i=0;i<4;i++){
        int r_check = h+dr[i];
        int c_check = w+dc[i];
        
        if(r_check>=0 && r_check<board.size() && c_check>=0 && c_check<board.size()){
            if(targetColor == board[r_check][c_check]){
                answer++;
            }
            
        }
    }
    return answer;
}
