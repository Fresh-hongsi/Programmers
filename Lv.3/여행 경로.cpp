#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <limits.h>
#include <map>
using namespace std;

vector<vector<pair<int,bool>>> adjList(10000); // 인접리스트, 이차원 벡터의 행 인덱스: 각 공항 번호, pair<int,bool>: 목적지 공항 번호, 방문되었는지 여부
vector<string> airport; // 각 공항의 인덱스가 곧 인접리스트의 공항번호 값이 됨
map<string, int> m;  // 공항, 공항번호 관리 map
vector<string> answer; // 문자열로 된 정답
vector<int> tempAnswer; // 인덱스 번호로 된 정답
int counter = 1; // 항로에서 거쳐갈 공항 개수
bool flag = false; // 탈출 조건 감시용

// a - i , s
// i - a, s
// s - a

void bt(int cur){
    
    // 만약, 다 성공적으로 순회했다면, 탈출
    if(tempAnswer.size()==counter){
        flag = true;
        return;
    }
    
    // 다음 공항 방문
    for(pair<int,bool> & k : adjList[cur]){ // 중요!! 참조자로 받아와야, k.second를 변경할 수 있다.
            if(k.second==false){ // 다음 공항 방문 안했으면
                k.second=true; // 방문 표시
                tempAnswer.push_back(k.first); // 방문한 공항을 tempAnswer에 추가
                bt(k.first); // 한 depth 더 파봄 
                if(flag==true){ // 만약 성공적으로 다 방문했다면, 탈출
                    return;
                }
                else{ // 다시 탐색 시도해야하는 경우, 
                    tempAnswer.pop_back(); // 마지막 방문한 공항을 pop
                    k.second = false; // 방문표시 취소
                }
            }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    

    // 모든 항로 정보를 vector로 받아서, 중복 제거, 그 후 인덱스를 번호로 공항 세팅
    for(int i=0;i<tickets.size();i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        airport.push_back(start);
        airport.push_back(end);
       
    }
    
    // 중복 제거를 위해 정렬한 후 unique함수 사용
    sort(airport.begin(),airport.end());
    airport.erase(unique(airport.begin(),airport.end()),airport.end());
    
    // 현재 공항 이름과 공항 번호를 map으로 관리
    for(int i=0;i<airport.size();i++){
        m[airport[i]]=i;
    }
    
    // 공항 번호, 다음 항로, 방문 여부를 인접리스트로 관리
    for(int i=0;i<tickets.size();i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        adjList[m[start]].push_back(make_pair(m[end],false));
        counter++; // 총 거쳐야할 항로 개수 count
       
    }
    
    // 각 인접리스트의 vector에 대해 오름차순 정렬
    for(int i=0;i<adjList.size();i++){
        sort(adjList[i].begin(),adjList[i].end());
    }
    
    // icn공항 인덱스 번호를 tempAnswer에 넣은 후, 백트래킹 시작
    tempAnswer.push_back(m["ICN"]);
    bt(m["ICN"]);
    
    // tempAnswer에 저장된 인덱스 번호로만 된 정답을 공항 문자열로 변환시켜서 정답 출력
    for(auto k:tempAnswer){
        answer.push_back(airport[k]);
    }
    
    return answer;
}



