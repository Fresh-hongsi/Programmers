#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
vector<vector<int>> adjList(101); // 인접리스트
int cnt = 0; // 총 떨어져 나간 송전탑 개수

void BFS(int start, int end){
    
    queue<int> q;
    vector<bool> visited(101,false); // 방문 표시 배열
    
    visited[start]=true; // 인자로 들어온 start 송전탑은 방문표시 true해주기
    visited[end]=true; // 인자로 들어온 end 송전탑도 방문표시 true 해주기
    
    cnt = 1; // 총 떨어져 나간 송전탑 개수의 합은 초기에 1임
    
    // start 쪽의 송전탑 뭉텅이 찾기
    q.push(start); 
    while(!q.empty()){
        
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<adjList[cur].size();i++){
            int next = adjList[cur][i];
            
            if(visited[next]==false){
                cnt++;
                q.push(next);
                visited[next]=true;
            }
        }
    }
}



int solution(int n, vector<vector<int>> wires) {

    int answer = 101;
    // 인접리스트에 전선 저장
    for(auto wire : wires){
        adjList[wire[0]].push_back(wire[1]);
        adjList[wire[1]].push_back(wire[0]);
    }
    
    // 모든 경우에 대해 조사하며 최솟값 찾기
    for(auto wire: wires){
        BFS(wire[0],wire[1]); 
        answer=min(answer,abs(cnt*2-n)); 
    }
    
    return answer;
}
