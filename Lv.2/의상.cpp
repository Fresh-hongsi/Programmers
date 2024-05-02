#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    
    map<string, int> m;
    int answer = 1;
    
    for(int i=0;i<clothes.size();i++){     
        string item = clothes[i][0];
        string category = clothes[i][1]; 
        m[category]++; // 각 카테고리에 대한 의상 추가
    }
    
    // 모든 아이템수 +1 씩 곱하고, 아무것도 안입는 경우 1가지 제외
    for(auto k : m){
        
        answer*=k.second+1;
    }
    
    answer-=1;
    
    return answer;
}

// a: 1 2 3
// b: 4 5
// c: 6
// d: 7 8 9 
