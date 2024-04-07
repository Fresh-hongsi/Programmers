#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>
using namespace std;

// 커스텀 비교 함수
bool comp(pair<int,double> a, pair<int,double> b){
    
    // 만약 실패율 값이 다르다면, 실패율은 내림차순 정렬
    if(a.second!=b.second){
        return a.second>b.second;
    }
    
    // 만약 실패율이 같다면, 스테이지 번호의 오름차순 정렬
    else{
        return a.first<b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer; // 정답 반환할 벡터
    vector<pair<int,double>> silpaeyul; // 각 단계별 싵패율을 저장할 vector
    map<int, int> stageMemberMap; // 각 단계별 도전 중인 회원 수를 저장할 map
    
    sort(stages.begin(),stages.end()); // 오름차순 정렬
    
    // 각 단계별 도전 중인 회원 수 구하기
    // 모든 단계에 대한 도전자 수는 처음에 0으로 세팅
    for(int i=1;i<=N;i++){
        stageMemberMap[i]=0;
    }
    // 그 후 stages 벡터를 관찰하며 map을 세팅
    for(int i=0;i<stages.size();i++){ 
        stageMemberMap[stages[i]]++;
    }
    
    // 각 단계별 실패율 저장
    int remainMemberNum = stages.size(); // 각 스테이지에 도달한 플레이어 수
    int curStage = 1; // 단계
    for(auto num : stageMemberMap){
        
        double ratio = 0; // 스테이지에 도달한 유저가 없는 경우에 대비해 초기 실패율은 0으로 세팅
        if(num.second!=0){
            ratio = (double)num.second/(double)remainMemberNum; // 스테이지에 도달한 유저가 있는 경우 실패율 세팅
        }
        
        remainMemberNum-=num.second; // 스테이지에 도달한 플레이어 수 다시 세팅
        silpaeyul.push_back(make_pair(curStage,ratio)); // 실패율 벡터에 이를 저장
    
        curStage++; // 스테이지 증가 
        if(curStage>N) // N값을 넘는 stage에 대한 실패율은 계산할 필요 없음
            break;
        
    }
    
    sort(silpaeyul.begin(),silpaeyul.end(),comp); // 커스텀 정렬에 맞춰서 비교 시작
    for(int i=0;i<silpaeyul.size();i++){
        answer.push_back(silpaeyul[i].first);
    }
    return answer;
}

// 단계 수
// 1: 1    1/8
// 2: 3    3/7
// 3: 2     2/4
// 4: 1     1/2
// 5: 0      0/1

// 1: 0
// 2: 0
// 3: 0
// 4: 5/5 1
