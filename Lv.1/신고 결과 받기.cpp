#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string,map<string,int>> memberReportMap; // 각 유저가 신고한 사람을 관리할 중첩 map
    // m: f-1, n-1    
    // a: f-1, m-1
    // f: n-1
    // 이런 식으로
    
    map<string,int> totalReport; // 각 회원이 몇 번 신고되었는 지 관리할 map
    // m:1
    // f:2
    // a:0
    // n:2
    // 이런 식으로
    
    
    // 두가지의 map 초기 세팅
    for(int i=0;i<id_list.size();i++){
        totalReport[id_list[i]]=0;
        memberReportMap[id_list[i]]; // 이렇게 하면 중첩된 map에서 모든 id에 대해 식별할 수 있다
    }
    
    // 멤버별로 자신이 신고한 report 등록
    for(int i=0;i<report.size();i++){
        stringstream ss(report[i]);
        string from; string to;
        ss>>from>>to;
        
        if(memberReportMap[from].find(to)!=memberReportMap[from].end()){ // 신고 기록이 있는 경우 
            continue;
        }else{ // 신고 기록이 없는 경우
            
            memberReportMap[from][to]=1; // 자신의 신고 기록에 이를 저장
            totalReport[to]++; // 전체 신고 관리 현황에 해당 멤버 한 명 추가
        }
    }
    
    vector<string> suspendedMember; // 정지될 멤버 저장할 벡터
    for(auto member : totalReport){
        if(member.second>=k){
            suspendedMember.push_back(member.first);
        }
    }

    
    for(auto member : id_list){ // 모든 유저에 대해
        int count = 0;
        for(auto target : suspendedMember){ // 정지대상자를 신고한 이력이 있는 지 확인하고, 메일 발송해야함
            if(memberReportMap[member].find(target) != memberReportMap[member].end()){
                count++;
            }
        }
        answer.push_back(count);
    }    
    return answer;
}


    

