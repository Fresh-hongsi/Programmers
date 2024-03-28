#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    
    set<int> s; // 중복하지 않는 수를 담기 위한 set
    int initialSize = elements.size(); // 초기 원형 수열 길이
    
    // 순환해야하므로 기존 원형 수열을 뒤에 복제해서 붙여준다 (컨베이어 벨트처럼)
    for(int i=0;i<initialSize;i++){
        elements.push_back(elements[i]);
    }
    
    // i: 내가 만들 부분 수열 길이
    // j: 부분수열의 시작 인덱스
    // k: 내가 정한 i번만큼 반복하며 temp 값을 합해가면서 변화시키기 위함
    for(int i=1;i<=initialSize;i++){
        
        int temp;
        for(int j=0;j<initialSize;j++){
            temp=0;
            for(int k=0;k<i;k++){
                temp+=elements[j+k];
            }
            s.insert(temp); // set에 부분 수열의 함을 넣어보기 -> 중복되는 경우 안들어갈 것
        }
        
        
    }
    
    return s.size(); // 정답 반환
}
