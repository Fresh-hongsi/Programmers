#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    
    vector<int> fibo(100001,0);
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=1;
    
    for(int i=3;i<=n;i++){
        fibo[i]=(fibo[i-2]+fibo[i-1])%1234567;
    }
    
    int answer = fibo[n];
    return answer;
    
}


// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// using namespace std;

// int solution(int n) {
    
//     int dp[100001]={0,};
//     dp[0]=0;
//     dp[1]=1;
//     dp[2]=1;
//     dp[3]=2;
    
//     for(int i=2;i<=n;i++){
//         dp[i]=(dp[i-1]+dp[i-2])%1234567;
//     }
//     int answer = dp[n];
//     return answer;
// }
