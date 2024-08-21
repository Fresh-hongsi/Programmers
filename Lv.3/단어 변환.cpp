#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <limits.h>
using namespace std;
int counter = 51; // 최대 변환 과정 개수
vector<bool> visited(51,false); // 방문 표시 배열
bool flag = false; // 변환 과정을 거쳐 단어를 찾을 수 있는 지 없는 지에 대한 여부

void backtracking(string cur, string target, int depth, vector<string> w){
    
    // 변환 과정을 거쳐 찾은 경우
    if(cur == target){
        flag = true; // 찾음을 표시
       
        // 현재 찾은 depth가 counter값보다 작다면, counter값 변경
        if(depth < counter){
           counter = depth; 
        }
        return;
    }
    
    // words에 있는 단어 중, 방문하지 않았고, 철자 하나만 다른 것에 대해 dfs시도
    for(int i=0;i<w.size();i++){
        
        if(visited[i]==false){
            int cnt = 0; // 몇 개의 철자가 같은 지 측정할 카운터
            for(int j=0;j<w[i].length();j++){
                if(cur[j]==w[i][j]){
                    cnt++;
                }
            }
            if(cnt==cur.length()-1){ // 만약 cur.length-1개가 같다면, dfs 가능
                visited[i]=true; // 방문표시
                backtracking(w[i],target,depth+1,w); // dfs
                    visited[i]=false; // 방문표시 초기화
            }
        }
        
    }
}

int solution(string begin, string target, vector<string> words) {
    
    backtracking(begin,target,0,words);
    
    // 만약 찾지 못했다면 0
    if(flag==false){
        counter=0;
    }
    return counter;
}
