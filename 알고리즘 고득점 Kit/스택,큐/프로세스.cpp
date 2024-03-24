#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    queue<pair<int,int>> q;
    deque<int> dq;
    
    for(int i=0;i<priorities.size();i++){
        dq.push_back(priorities[i]);
    }
    
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(priorities[i],i));
    }
    
    sort(dq.begin(),dq.end(),greater<>());
    
    while(dq.size()>0){
        
        
        int curMax = dq[0];
        dq.pop_front();
        
        while(q.front().first!=curMax){
            
            pair<int,int> cur = q.front();
            q.pop();
            q.push(cur);
        }
        
        if(location == q.front().second){
            
            break;
        }
        
        else{
            q.pop();
            answer++;
        }
        

        
        
        
    }
    
    
    return answer;
}
