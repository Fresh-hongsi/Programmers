#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// bfs로 풀기
int N = 0;
vector<vector<int>> adjList(20000);  // 인접리스트
vector<bool> visited(20000,false); // 방문표시배열
vector<pair<int,int>> res; // 1번 노드에서 각 노드까지의 거리를 저장할 벡터
int maxLen = 0; // 가장 먼 노드까지의 길이

void bfs(int s,int l){
    
    queue<pair<int,int>> q;
    q.push(make_pair(s,l));
    
    visited[s]=true;
    maxLen = l;
    
    while(!q.empty()){
        int curNode = q.front().first;
        int curLen = q.front().second;
        q.pop();
        
        for(auto k : adjList[curNode]){
            if(visited[k]==false){
                visited[k]=true;
                q.push(make_pair(k,curLen+1));
                res.push_back(make_pair(k,curLen+1));
                if(maxLen<curLen+1){
                    maxLen=curLen+1;
                }
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    
    int answer = 0;

    // 인접리스트 세팅
    for(int i=0;i<edge.size();i++){
        
        int from = edge[i][0]-1;
        int to = edge[i][1]-1;
        
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    
    // 1번 노드부터 1번노드까지의 거리 세팅
    res.push_back(make_pair(0,0));
    
    // 너비우선탐색 시작
    bfs(0,0);
    
    // 가장 먼 노드를 답에 추가
    for(int i=0;i<res.size();i++){
        if(maxLen==res[i].second){
            answer++;
        }
    }
    return answer;
}
