// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// long long solution(int n) {
//     long long answer = 0;
//     long long dp[2001]={0,};
    
//     dp[0]=1;
//     dp[1]=1;
    
    
//     for(int i=2;i<=n;i++){
        
//         dp[i] = (dp[i-2]+dp[i-1])%1234567;
       
//     }
    
//     answer = dp[n];
//     return answer;
// }
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> dp(2001,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=5;
    
    for(int i=5;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    answer = dp[n];
    return answer;
}
