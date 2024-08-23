#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <limits.h>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    queue<int> aQ; // a팀 나올 순서 큐
    queue<int> bQ; // b팀 나올 순서 큐
    
    sort(A.begin(),A.end()); // a팀 능력치 오름차순 정렬
    sort(B.begin(),B.end()); // b팀 능력치 오름차순 정렬
    
    // a,b팀을 각각 큐에 넣어주기
    for(int i=0;i<A.size();i++){
        aQ.push(A[i]);
        bQ.push(B[i]);
    }
    
    while(!aQ.empty() && !bQ.empty()){
        int aFront = aQ.front(); // a팀 가장 앞 사람
        int bFront = bQ.front(); // b팀 가장 앞 사람
        
        aQ.pop();
        bQ.pop();
        
        // b가 이길 수 있는 케이스-> a,b팀 한명씩 pop
        if(aFront<bFront){
            answer++;
        }
        
        
        // 현재로썬, b가 a를 이길 수 없는 케이스
        // b가 a를 이길 수 있을 때까지, 이길 수 없는 b팀 사람을 temp에 저장했다가, 이길 수 있는 경우를 찾으면 temp값을 bQ뒤에 다 push
        else{
            vector<int> temp;
            temp.push_back(bFront);
            
            while(!bQ.empty()){
                
                int nextFront = bQ.front();
                bQ.pop();
            
                if(nextFront > aFront){
                    answer++;
                    break;
                }
                else{
                    temp.push_back(nextFront);
                }
            }
            
            for(auto k: temp){
                bQ.push(k);
            }
        }
    }
    
    return answer;
}

// 1 3 5 7
// 2 2 2 8

// --> a,b둘다 오름차순으로 정렬하고
// 2 8 2 2
    
    
