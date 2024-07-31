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



// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <functional>
// using namespace std;

// int solution(vector<vector<int>> triangle) {
//     int answer = 0;
    
//     vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),0));
//     vector<int> result; // 마지막 행에 도달했을 때 모든 결과값을 담을 벡터
    
//     dp[0][0] = triangle[0][0];
//     dp[1][0] = dp[0][0]+triangle[1][0];
//     dp[1][1] = dp[0][0]+triangle[1][1];
    
//     for(int i=2;i<triangle.size();i++){
//         for(int j=0;j<triangle[i].size();j++){
//             if(j==0){
//                 dp[i][j]=dp[i-1][j]+triangle[i][j];
//             }
//             else if(j==triangle[i].size()-1){
//                 dp[i][j]=dp[i-1][j-1]+triangle[i][j];
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
//             }
            
//             if(i==triangle.size()-1){
//                 result.push_back(dp[i][j]);
//             }
//         }
//     }
    
//     answer = *max_element(result.begin(),result.end());
//     return answer;
// }

// // 7 0 0 0 0
// // 3 8 0 0 0 
// // 8 1 0 0 0
// // 2 7 4 4 0
// // 4 5 2 6 5
    
// // dp[0][0]=triangle[0][0]=7
// // dp[1][0] = dp[0][0]+triangle[1][0]=10
// // dp[1][1] = dp[0][0]+triangle[1][1]=15
// // dp[2][0] = dp[1][0]+triangle[2][0]=18
// // dp[2][1] = max(dp[1][0],dp[1][1])+triangle[2][1] = 16
// // dp[2][2] = dp[1][1]+triangle[2][2] = 15
// // dp[3][0] = dp[2][0]+triangle[3][0]

// // 7 0 0 0 0
// // 10 15 
// // 18 16 15
// // 20 25 20 19
// // 24 30 37 26 24
