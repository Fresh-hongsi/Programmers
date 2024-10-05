// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;


// int solution(vector<int> topping) {
//     int answer = 0;
    
//     map<int,int> ob; // 형이 모은 토핑 관리하는 맵 key: 토핑 번호,  val: 토핑 개수
//     map<int,int> yb; // 동생이 모은 토핑 관리하는 맵 key: 토핑 번호,  val: 토핑 개수
    
//     // 먼저 동생한테 모든 토핑 다 주기
//     for(int i=0;i<topping.size();i++){
//         yb[topping[i]]++;
//     }
    
//     // 앞에서 순차적으로 가며 형과 동생 토핑 수 재세팅
//     for(int i=0;i<topping.size();i++){
//         ob[topping[i]]++;
//         yb[topping[i]]--;
//         if(yb[topping[i]]==0){
//             yb.erase(topping[i]);
//         }
        
//         if(ob.size()==yb.size()){
//             answer++;
//         }
//     }
    
//   return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> m; // 전체 토핑 관리 map
    set<int> s; // 앞에서 순차적으로 토핑 개수 구해나감
    
    // 전체 토핑 현황 구하기
    for(int i=0;i<topping.size();i++){
        m[topping[i]]++;
    }
    
    // 앞에서부터 순차적으로 토핑 종류 구하기
    for(int i=0;i<topping.size();i++){
        s.insert(topping[i]); // 앞 분할의 토핑 종류 추가
        m[topping[i]]--; // 전체 토핑에서는 제거
        
        if(m[topping[i]]==0){ // 만약 전체 토핑 관리 map에서 해당 토핑이 0이되는 순간엔, 뒷 분할에 해당 토핑은 없는 것이므로 제거
            m.erase(topping[i]);
        }
        
        // 만약 앞 토핑 종류와 뒷 토핑 종류의 개수가 같다면 answer 추가
        if(s.size()==m.size()){
            //cout<<i<<' ';
            answer++;
        }
    }
    return answer;
}

// 100000000
    
// 1:4
// 2:2
// 3:1
// 4:1

    
// 1 2 3 3 4
