#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <sstream>
#include <limits.h>
#include <set>
using namespace std;

// 누적합 + set 이용 --> 시간복잡도 고려
int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int n = elements.size();
    
    // 수열 이어붙이기 -> 원형 순열이기 때문
    for(int i=0;i<n;i++){
        elements.push_back(elements[i]);
    }
    
    // 먼저 누적합을 저장
    vector<int> accumulatedSum;
    int sum = 0;
    for(int i=0;i<elements.size();i++){
        sum+=elements[i];
        accumulatedSum.push_back(sum);
    }
    
    // 누적합에서, 규칙을 활용하여 부분 수열 합을 구해보고 set에 저장
    for(int size = 1; size<=n;size++){
        s.insert(accumulatedSum[size-1]);
        for(int i=size;i<accumulatedSum.size();i++){
            s.insert(accumulatedSum[i]-accumulatedSum[i-size]);
        }
    }
    
    answer = s.size();
    return answer;
}

// 7 9 1 1 4 7 9 1 1 4

// 7 16 17 18 22 29 38 39 40 44

// 7 9 1 4
// 16 10 2 5 11
// 17 

// #include <string>
// #include <vector>
// #include <set>
// #include <iostream>
// using namespace std;

// int solution(vector<int> elements) {
    
//     set<int> s; // 중복하지 않는 수를 담기 위한 set
//     int initialSize = elements.size(); // 초기 원형 수열 길이
    
//     // 순환해야하므로 기존 원형 수열을 뒤에 복제해서 붙여준다 (컨베이어 벨트처럼)
//     for(int i=0;i<initialSize;i++){
//         elements.push_back(elements[i]);
//     }
    
//     // i: 내가 만들 부분 수열 길이
//     // j: 부분수열의 시작 인덱스
//     // k: 내가 정한 i번만큼 반복하며 temp 값을 합해가면서 변화시키기 위함
//     for(int i=1;i<=initialSize;i++){
        
//         int temp;
//         for(int j=0;j<initialSize;j++){
//             temp=0;
//             for(int k=0;k<i;k++){
//                 temp+=elements[j+k];
//             }
//             s.insert(temp); // set에 부분 수열의 함을 넣어보기 -> 중복되는 경우 안들어갈 것
//         }
        
        
//     }
    
//     return s.size(); // 정답 반환
// }

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// using namespace std;

// int solution(vector<int> elements) {
//     int answer = 0;
//     vector<int> ans;
//     vector<int> temp;
//     for(int i=0;i<elements.size();i++){
//         int t = elements[i];
//         temp.push_back(t);
//     }
//     for(int i=0;i<elements.size();i++){
//         int t = elements[i];
//         temp.push_back(t);
//     }
    
//     for(int i=1;i<=elements.size();i++){ // 1개부터 n개까지
//         for(int j=0;j<elements.size();j++){ // 시작점
//             int t = 0;
//             for(int k=j;k<i+j;k++){
//                 t+=temp[k];
//             }
//             ans.push_back(t);
//         }
//     }
    
//     sort(ans.begin(),ans.end());
//     ans.erase(unique(ans.begin(),ans.end()),ans.end());
    
//     answer = ans.size();
//     return answer;
// }


// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <functional>
// #include <map>
// using namespace std;

// int solution(vector<int> elements) {
//     int answer = 0;
//     int size = elements.size(); // 최초 elements 벡터 길이
    
//     // 문제 풀이 효율성을 위해 기존 elements 벡터에다가 elements 벡터 요소를 이어붙여줌
//     for(int i=0;i<size;i++){
//         elements.push_back(elements[i]);
//     }
    
//     // 부분 배열의 합을 저장할 map -> key:연속 부분 배열의 합, val: 해당 연속 부분 배열의 합의 개수 -> 0 또는 1만 가짐 
//     map<int,int> m;
    
//     // 연속 부분 배열의 합을 구해보기
//     for(int i=1;i<=size;i++){ //i: 현재 탐색할 부분 배열의 길이
//         for(int j=0;j<size;j++){//j: 현재 탐색 중인 부분 배열의 첫번째 인덱스
//             int sum = 0;
//             for(int k=j;k<j+i;k++){//k: 현재 탐색 중인 부분 배열의 인덱스
//                 sum+=elements[k];
                
//             }
            
//             if(m.find(sum)!=m.end()){ // 구한 연속 부분 배열의 합인 sum이 map에 이미 존재한다면
//                 continue;
//             }
//             else{ // 존재 하지 않는 경우, map에 추가
//                 m[sum]=1;
//             }
//         }
//     }
    
//     // map의 크기가 곧 찾아낸 모든 부분 배열의 합의 개수
//     answer=m.size();
//     return answer;
// }
