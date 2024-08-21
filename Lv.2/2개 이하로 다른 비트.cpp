#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <math.h>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();i++){
        long long cur = numbers[i];
        
        // cur이 짝수일 경우, cur+1이 만들 수 있는 가장 작은 수
        if(cur%2==0){
            long long result = cur+1;
            answer.push_back(result);
        }
                              
        // cur이 홀수일 경우
        // 가장 뒤에서부터 첫 0이 나오는 위치 조사,
        // 해당 0을 1로 바꾸고,
        // 찾은 위치의 0의 오른쪽 뒤에 나오는 1중에 가장 가까운 위치를 0으로 바꾸면, 만들 수 있는 가장 작은 수
        else{
            
            long long base = 1;
            while((base | cur) == cur){
                base*=2;
            }
            long long result = cur+base;
            result-=(base/2);
            answer.push_back(result);
        }
        
    }
    return answer;
}
