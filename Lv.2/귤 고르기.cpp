#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// map을 value로 정렬하고 싶을 때는, map을 vector로 옮긴 후 comp 통해 정렬 수행해야함
bool comp(pair<int,int> a, pair<int,int> b){
    
    return a.second > b.second; // value기준 내림차순
}
int solution(int k, vector<int> tangerine) {
    
    int answer = 0;
    map<int,int> m; // key: 귤 크기, value: 각 크기의 귤 개수
    
    // 크기별 귤 개수를 map에 저장
    for(int i=0;i<tangerine.size();i++){
        m[tangerine[i]]++;
    }  
    
    // 정렬을 위해 map을 vector로 복사
    // 중요!!! map의 key value 쌍은 pair와 호환이 된다.
    vector<pair<int,int>> v(m.begin(),m.end());
    
    // value 기준 오름차순 정렬 수행
    sort(v.begin(),v.end(),comp);
    
    int count = 0;
    
    for(int i=0;i<v.size();i++){
        
        if(count>=k)
            break;
        
        count+=v[i].second;
        answer++;
    }
    

    return answer;
}
