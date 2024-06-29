#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    int counter = 0; // location에 해당하는 프로세스가 몇번째에 나오는지 셀 카운터
    
    deque<pair<int,int>> dq; 
    
    for(int i=0;i<priorities.size();i++){
        dq.push_back(make_pair(priorities[i],i)); //덱에 <프로세스 우선순위, 위치> 값을 pair로 저장
    }
    
    
    while(!dq.empty()){
        int curPriority = dq.front().first;
        int curLocation = dq.front().second;
        
        dq.pop_front(); // 일단 가장 앞에 있는 프로세스 꺼내기
        
        bool flag=false;
        
        for(auto k: dq){
            if(k.first>curPriority){ // 만약 더 우선순위가 높은 프로세스를 발견했다면
                flag=true;
                dq.push_back(make_pair(curPriority,curLocation)); // 뒤에 다시 넣어주기
                break;
            }
        }
        
        if(flag==false){ // 만약 우선순위가 더 높은 프로세스를 발견해지 못했다면
            counter++; // 해당 프로세스를 실행하기
            
            if(curLocation==location) // 만약 찾는 위치의 프로세스라면
            {
                answer=counter; // 답 구했음
                break;
            }
        }
        
        
    }
    
    
    return answer;
}

// 9 2
// 1 3
// 1 4
// 1 0
// 1 1
