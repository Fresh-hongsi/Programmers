#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    queue<int> mainQ; // 메인 컨베이어벨트
    stack<int> subBelt; // 보조 컨베이어벨트
    
    // 메인 컨베이어벨트에 들어오는 상자 세팅 1,2,3,4,5 ...
    for(int i=1;i<=order.size();i++){
        mainQ.push(i);
    }
    
    // 찾고자 하는 상자 번호 순차적으로 조사
    for(int i=0;i<order.size();i++){
        int curTarget = order[i]; // 현재 찾아야할 상자 번호
        
        // 보조 컨베이어벨트부터 조사
        if(subBelt.size()>0){ // 보조 컨테이어벨트에 상자가 들어있다면, top을 먼저 살펴보기
            if(curTarget==subBelt.top()){ // 찾은 경우
                subBelt.pop(); // 보조에서 상자 빼서
                answer++; // 트럭에 넣기
                continue; // 다음 상자 번호 찾기
            }
        }
        
        // 보조 컨베이어벨트에서 찾을 수 없는 경우, 
        // 메인 컨베이어벨트에서 찾아보기
        bool flag = false; // 더이상 진행할 수 없을 경우를 제어하기 위한 조건
        while(!mainQ.empty()){
            
            flag = false; // 메인 벨트에서 상자 찾을 때 true로 바꾸기
            int mainQFront = mainQ.front(); // 메인 컨베이어벨트 가장 앞에 있는 상자
            mainQ.pop(); // 꺼내기
            
            if(mainQFront==curTarget){ // 실을 상자번호와 일치한다면
                answer++; // 트럭에 넣기
                flag = true; // 더이상 mainQ를 살펴볼 이유 없음
                break; // 다음 상자 번호 찾기
            }
            else{ // 실을 상자번호와 일치하지 않다면
                subBelt.push(mainQFront); // 보조 컨베이어벨트에 넣기
            }
        }
        // 만약 flag가 true라면, 바로 다음 찾을 상자 번호 조사
        if(flag == true){
            continue;
        }
        // 만약 메인 컨베이어벨트가 비었다면, 더이상 진행할 수 없는 경우임
        if(mainQ.empty()){
            break;
        }
    }
    
    
    
    return answer;
}

// 1 2 3 4 5
// 4 3 1 2 5
// 1 2 3
//4 3 
    
// 1 2 3 4 5
