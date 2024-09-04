#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string,string>> cmdId; // 명령어와 id값을 pair로 묶어서 vector에 저장
    map<string,string> idName; // id값과 그에 해당하는 name를 관리할 map

    // record를 바탕으로, cmdId와 idName 세팅하기
    for(int i=0;i<record.size();i++){
        string temp = record[i];
        stringstream ss(temp);
        string cmd; // 수행동작
        string id; // 회원의 id
        string name; // 회원의 이름
        ss>>cmd>>id>>name;
        
        // 입장했을 경우
        if(cmd=="Enter"){
            
            cmdId.push_back(make_pair(cmd,id)); // 순서를 위해 vector에 저장
            idName[id]=name; // 현재 id에 해당하는 name값 업데이트
            
        }
        // 나갔을 경우
        else if(cmd=="Leave"){ 
            cmdId.push_back(make_pair(cmd,id)); // 순서를 위해 vector에 저장
        }
        
        // 이름 변경했을 경우
        else{ // Change
            idName[id]=name;  // 현재 id에 해당하는 name값 업데이트
        }

    }
    
    // 값 출력
    for(auto k : cmdId){
        if(k.first == "Enter"){
            answer.push_back((idName[k.second])+"님이 들어왔습니다.");
        }
        else if(k.first == "Leave"){
            answer.push_back((idName[k.second])+"님이 나갔습니다.");
        }
    }


    return answer;
}

// enter 1234  1234 prodo
// enter 4567  4567 ryan
// leave 1234  
// enter 1234
// change 4567
