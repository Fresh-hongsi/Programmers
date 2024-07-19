#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char,int> m;
    vector<string> edited_skill_trees;
    // 맵에 스킬 종류와 순서 세팅
    for(int i=0;i<skill.length();i++){
        char cur = skill[i];
        m[cur]=i;
    }
    
    // 스킬 트리에서 스킬과 관련 없는 것 제거하기
    for(int i=0;i<skill_trees.size();i++){
        string cur = skill_trees[i];
        string edited = "";
        for(int j=0;j<cur.length();j++){
            if(m.find(cur[j])!=m.end()){ // 있으면
                edited+=cur[j];
            }
            else{
                continue;
            }
        }
        edited_skill_trees.push_back(edited);
    }
    
    // 비교 후 가능하면 카운트
    for(auto k: edited_skill_trees){
        
        bool flag = true;
        for(int i=0;i<k.length();i++){
            if(skill[i]==k[i]){
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        
        if(flag==true){
            answer++;
        }
    }
    
    
    return answer;
}



// bcd cbd cb bd
