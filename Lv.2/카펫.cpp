// #include <string>
// #include <vector>
// #include <math.h>
// #include <algorithm>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
    
//     int total=brown+yellow; // 전체 카펫의 타일 수 계산
//     int j=0; // 열 개수는 처음에 0으로 세팅
    
//     for(int i=1;i<=sqrt(total);i++) // 행 개수를 가변적으로 반복문 돌려보기
//     {
//         if(total%i==0) // 만약 전체 타일 수에서 행을 나눴을 때 나머지가 0이면 유효한 열 개수임
//         {
//             j=total/i;
//         }
        
//         // 노란색 타일 수 계산 값이 입력받은 yellow수와 같고, 
//         // 전체 total에서 계산한 노란 타일 수를 뺐을 때 그 값이 brown이랑 같다면
//         // 올바르게 구한 것임
//         // 따라서 for문 break
        
//         if(((i-2)*(j-2))==yellow && (total-(i-2)*(j-2))==brown)
//         {
//             answer.push_back(j);
//             answer.push_back(i);
//             break;
//         }
//     }
//     return answer;
// }


#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown+yellow;
    
    for(int i=brown;i>0;i--){
        if(total%i==0){
            int x = i;
            int y = total/x;
            
            if(((x-2)*(y-2))==yellow){
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
        
    }
    return answer;
}
