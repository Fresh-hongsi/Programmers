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

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <functional>
// #include <iostream>
// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer = 0;
    
//     priority_queue<int,vector<int>,greater<int>> pq;

//     for(int i=0;i<scoville.size();i++){
//         int cur = scoville[i];
//         pq.push(cur);
//     }

//     while(pq.size()>=2){
//         if(pq.top()>=K){
//             break;
//         }
//         else{
//             int top1 = pq.top();
//             pq.pop();
//             int top2 = pq.top();
//             pq.pop();
//             int next = top1+2*top2;
//             pq.push(next);
//             answer++;
//         }
//     }
    
//     if(pq.top()<K){
//         answer=-1;
//     }
//     return answer;
// }
