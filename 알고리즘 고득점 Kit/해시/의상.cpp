#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
   
    unordered_map<string,int> m;
    for(int i=0;i<clothes.size();i++){
        
        string name = clothes[i][0];
        string category = clothes[i][1];
        
        m[category]++;
        
    }
    
    // 여사건 원리 사용 -> 각 카테고리에 있는 의상 수 +1 한 상태에서 곱함
    // 아무것도 안고른 경우에 대해서 1가지를 빼기
    
    int answer = 1;
    for(auto p : m){
        answer*=(p.second+1);
    }
  
    return answer-=1;
}
