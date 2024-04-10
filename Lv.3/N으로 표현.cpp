#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int getN_s(int N, int idx){ // N을 idx만큼 이어붙인 정수 형태를 반환 
    
    int r = N;
    
    for(int i=0;i<idx-1;i++){
        N = N*10+r; //5 55 555
    }
    
    return N;
    
}

int solution(int N, int number) {
    int answer = -1;
    
    vector<unordered_set<int>> DP(9); 
    // dp[0]: N 0개로 만들 수 있는 모든 수를 set에 저장
    // dp[1]: N 1개로 만들 수 있는 모든 수를 set에 저장 
    // ...
    // dp[8]: N 8개로 만들 수 있는 모든 수를 set에 저장
    
    if (N == number){ // 만약 N과 number이 같다면 N 1개로 바로 number을 완성할 수 있는 것이므로 답 반환
        return 1; 
    }
    
    
    // 핵심 원리
    // N 2개로 만들 수 있는 수 : NN 또는 DP[1]과 DP[1]의 사칙연산을 한 형태임
    // N 3개로 만들 수 있는 수 : NNN 또는 DP[1] ? DP[2]의 사칙연산 또는 DP[2] ? DP[1]의 사칙연산
    // N 4개로 만들 수 있는 수 : NNNN 또는 (DP[1] ? DP[3]) 또는 (DP[2] ? DP[2]) 또는 (DP[3] ? DP[1])  
    
    for(int k=1; k<=8; k++){
        DP[k].insert(getN_s(N,k)); // k값에 맞춰서 각 DP[k]에 N NN NNN NNNN 과 같은 형태 넣어주기
        
        // 여기서부턴 N을 k개 사용해서 만들 수 있는 모든 수를 찾아 넣어줌
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(i+j==k){
                    
                    for(int a : DP[i]){
                        for(int b : DP[j]){
                            
                            // a + b 시도
                            DP[k].insert(a+b);
                            
                            // a * b 시도
                            DP[k].insert(a*b);
                            
                            // a / b 시도
                            if(b != 0 && a/b>0){
                                DP[k].insert(a/b);
                            }
                            
                            // a - b 시도
                            if(a-b>=0){
                                DP[k].insert(a-b);
                            }
                        }
                    }
              
                }
                
            }
        }
        
        // 만약 현재 set에서 number을 찾을 수 있다면 반환
        if(DP[k].find(number)!=DP[k].end()){
                return k;
        }        
    }

    
    return answer;
}
