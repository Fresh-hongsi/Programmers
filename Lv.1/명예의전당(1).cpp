#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선순위 큐 선언
    
        
    vector<int> answer;
    
    for(int i=0; i<score.size();i++){
        if(pq.size()<k){
            pq.push(score[i]);
        }
        
        else{
            if(score[i]>pq.top()){
                pq.pop();
                pq.push(score[i]);
            }
            
        }
        
        answer.push_back(pq.top());
    }
    

    return answer;
}
