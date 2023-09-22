#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // 배열 A는 오름차순 , 배멸 B는 내림차순으로 했을 때, 누적된 값의 합이 최소가 된다
    sort(A.begin(),A.end()); // 오름차순 정렬
    sort(B.begin(),B.end(),greater<>()); // 내림차순 정렬
    
    for(int i=0;i<A.size();i++){ // 누적된 값의 최소값 계산
        answer+=A[i]*B[i];
    }
    

    return answer;
}
