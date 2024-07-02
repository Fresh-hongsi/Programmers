#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
 
    // second가 많은 순서대로 정렬해야함
    
    if(a.second!=b.second){ // second가 다르다면
        return a.second>b.second;
    }
    
    else{
        return a.first<b.first;
    }
}


vector<int> solution(string s) {
    vector<int> answer;
    
    
    map<int,int> m; // key: 해당 숫자 val: 해당 숫자가 몇번 등장했는지
    
    // 문자열을 살펴보며, 숫자인 경우, 해당 숫자를 map의 key로 해서 몇 번 등장했는지 업데이트해감
    string cur = "";
    for(int i=0;i<s.length();i++){
        
        if(s[i]>='0' && s[i]<='9'){
            cur+=s[i];
        }
        
        if(s[i]=='}' || s[i]==','){
            if(cur!=""){
                m[stoi(cur)]++;    
            }
            cur="";
            
        }
    }
    
    // 가장 많이 등장한 것이 answer의 가장 앞에, 가장 적게 등장한 것이 answer의 가장 뒤에 등장해야함
    // 이를 정렬하기 위해, map의 요소를 vector로 옮긴 후 정렬 시도
    vector<pair<int,int>> tempVec;
    for(auto k: m){
        tempVec.push_back(make_pair(k.first,k.second));
    }
    
    sort(tempVec.begin(),tempVec.end(),comp);
    
    // 정렬된 tempVec의 first인자를 answer에 순차적으로 넣기
    for(auto k: tempVec){
        answer.push_back(k.first);
    }
    
    return answer;
}
