#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> m; // value, count
    
    // 맵 세팅
    for(int i=0;i<weights.size();i++){
        m[weights[i]]++; 
    }
    
    for(pair<long long, long long> k : m){
        
        // 같은 value값이 1개 이상인 경우, nC2
        if(k.second > 1){ 
            answer+=(k.second*(k.second-1))/2;
        }
        // 2:3의 case
        if((k.first*2)%3==0){
            answer+=((m[(k.first*2)/3])*k.second);
        }
        // 2:4의 case
        if((k.first*2)%4==0){
            answer+=((m[(k.first*2)/4])*k.second);
        }
        // 3:4의 case
        if((k.first*3)%4==0){
            answer+=((m[(k.first*3)/4])*k.second);
        }
        
    }
    return answer;
}

// case 종류
// 2 2 
// 2 3
// 2 4
// 3 2 = 2 3일 때 계산됨 
// 3 3 = 1 1일 때 게산됨
// 3 4 
// 4 2 = 4 2일 때 계산됨
// 4 3 = 4 3일 때 계산됨
// 4 4 = 1 1일 때 게산됨
