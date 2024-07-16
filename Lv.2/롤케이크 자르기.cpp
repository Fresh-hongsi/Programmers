#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;


int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> ob; // 형이 모은 토핑 관리하는 맵 key: 토핑 번호,  val: 토핑 개수
    map<int,int> yb; // 동생이 모은 토핑 관리하는 맵 key: 토핑 번호,  val: 토핑 개수
    
    // 먼저 동생한테 모든 토핑 다 주기
    for(int i=0;i<topping.size();i++){
        yb[topping[i]]++;
    }
    
    // 앞에서 순차적으로 가며 형과 동생 토핑 수 재세팅
    for(int i=0;i<topping.size();i++){
        ob[topping[i]]++;
        yb[topping[i]]--;
        if(yb[topping[i]]==0){
            yb.erase(topping[i]);
        }
        
        if(ob.size()==yb.size()){
            answer++;
        }
    }
    
  return answer;
}
