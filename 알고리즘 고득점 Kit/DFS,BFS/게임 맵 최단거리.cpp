#include<vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;
// bfs

int dr[4] = {-1,0,1,0}; // 상우하좌 행 변위
int dc[4] = {0,1,0,-1}; // 상우하좌 열 변위

int bfs(int targetR, int targetC, vector<vector<int>> &maps){
    
    int distance = 999999;
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,1));
    
    while(!q.empty()){
        
        int curR = get<0>(q.front());
        int curC = get<1>(q.front());
        int curLen = get<2>(q.front());
        // cout<<curR<<' '<<curC<<' '<<curLen<<'\n';
        q.pop();
        
        if(curR==targetR && curC==targetC){
            distance = curLen;
            return distance;
        }
        
        for(int i=0;i<4;i++){
            int nextR = curR+dr[i];
            int nextC = curC+dc[i];
            int nextLen = curLen+1;
            
            if(nextR>=0 && nextR<=targetR && nextC>=0 && nextC<=targetC){
                if(maps[nextR][nextC]==1){
                    q.push(make_tuple(nextR,nextC,nextLen));
                    maps[nextR][nextC]=0; // 다시 방문하지 못하도록 하기
                    
                }
            }
        }
    }
    
    return distance;
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int length = bfs(maps.size()-1,maps[0].size()-1,maps);
    if(length==999999){
        answer=-1;
    }else{
        answer = length;
    }
    return answer;
}
