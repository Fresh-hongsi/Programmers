#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
using namespace std;

// dp 활용
int solution(int n) {
    int answer = 0;
    
    vector<int>dp(60001,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=5;
    
    for(int i=4;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])%1000000007;
    }
    
    answer = dp[n];
    return answer;
}
