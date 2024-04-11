#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

//bfs
bool visited[201]={false,};
vector<vector<int>> adjList(201);

void bfs(int start){
    
    queue<int> q;
    
    visited[start]=true; // 시작 노드 방문표시
    q.push(start); // 큐에 시작점 넣어주기
    
    while(!q.empty()){
        
        int cur = q.front();
        q.pop();
        
        for(int next : adjList[cur]){
            if(visited[next]!=true) // 방문되지 않았다면
            {
                q.push(next);
                visited[next]=true;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 인접리스트 세팅
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(computers[i][j]==1){
                adjList[i+1].push_back(j+1);
                adjList[j+1].push_back(i+1);
            }
        }
    }
    
    // 각 시작 노드에 대해, 방문되지 않았으면 bfs 시도
    for(int i=1;i<=n;i++){
        if(visited[i]!=true){
            bfs(i);
            answer++; // 다른 네트워크이므로 1 추가
        }
    }
    
    
    return answer;
}
