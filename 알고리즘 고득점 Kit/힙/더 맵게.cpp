#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 우선순위큐 이용
int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>, greater<int>> pq; // 오름차순 pq
    
    // 우선순위큐에 삽입
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    // 2개 이상 남아있을 떄
    while(pq.size()>1){
        
        int cur = pq.top(); // 가장 작은 것 찾기
        pq.pop(); // 꺼내기
        
        if(cur>=K){ // 만약 k 이상이면 찾은 것
            break;
        }
        
        else{
            int p = pq.top(); // k 미만이면 섞어야함, 다음 낮은 스코빌 찾기
            pq.pop(); // 꺼내기
            int next = cur+(2*p);
            pq.push(next);
            answer++;
        }
    }
    
    if(pq.top()<K){
        answer=-1;
    }
    
    return answer;
}


