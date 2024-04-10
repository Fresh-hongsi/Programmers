#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int dp[101][101]={0,};
    
    // dp 에 연못 표시
    for(int i=0;i<puddles.size();i++){

        dp[puddles[i][1]][puddles[i][0]]=-1;
    }
    
    
    dp[1][1]=1; // 시작 위치는 1가지
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(dp[i][j]==-1){ // 물이 있는 경우 pass
                continue;
            }
            
            //dp[i][j]좌표는 dp[i-1][j]+dp[i][j-1]이다
            
            int a=0; // dp[i-1][j] 이 채워질 벼수
            int b=0; // dp[i][j-1] 이 채워질 변수
            
            if(dp[i-1][j]!=-1){
                a=dp[i-1][j];
            }
            if(dp[i][j-1]!=-1){
                b=dp[i][j-1];
            }
            
            dp[i][j]+=(a+b)%1000000007;
        }
    }
    
    answer = dp[n][m];
    
    
    
    
    return answer;
}
