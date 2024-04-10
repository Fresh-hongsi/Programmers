#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int dp[501][501]={0,};
    dp[0][0]=triangle[0][0]; // 가장 윗층 먼저 세팅
    
    // 2중 for문 돌면서 dp 값 채우기
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            
            if(j-1<0){ // 가장 왼쪽에 있는 칸의 경우
                dp[i][j] = dp[i-1][j]+triangle[i][j]; 
            }
            else{ // 그 외의 경우
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
            
        }
    }
    
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<dp[i][j]<<' ';
//         }
        
//         cout<<'\n';
//     }
    
    // 가장 아래있는 층을 arr 벡터에 넣고, 그 중 최댓값 찾기
    vector<int> arr;
    for(int i=0;i<triangle.size();i++){
        arr.push_back(dp[triangle.size()-1][i]);
    }
    
    answer = *max_element(arr.begin(),arr.end());
    return answer;
}

