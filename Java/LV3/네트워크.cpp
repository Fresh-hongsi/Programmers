#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

vector<vector<int>> adjList(201);
bool visited[200]={false,};

void bfs(int start){
    queue<int> q;
    visited[start]=true;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int k : adjList[cur]){
            if(visited[k]!=true){
                q.push(k);
                visited[k]=true;
            }
        }
    }
}

void dfs(int start){
    visited[start]=true;
    
    for(int k : adjList[start]){
        if(visited[k]!=true){
            dfs(k);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 인접리스트 세팅
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(computers[i][j]==1){
                if(i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i);
            //bfs(i);
            answer++;
        }

    }
    return answer;
}

// 0: 1
// 1: 0,2
// 2: 1
