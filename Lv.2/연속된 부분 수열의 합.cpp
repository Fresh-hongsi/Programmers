#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <limits.h>
using namespace std;

// 투포인터 활용
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    int min = 99999999;
    int resStart = 0;
    int resEnd = 0;
    
    
    while(start<sequence.size() && end<sequence.size()){
        if(sum==k){
            if(end-start<min){
                resStart = start;
                resEnd = end;
                min = end-start;
            }
            
            end++;
            // 인덱스 초과 예외처리
            if(end==sequence.size()){
                continue;
            }
            sum+=sequence[end];
        }
        
        else if(sum<k){   
            end++;
            
            // 인덱스 초과 예외처리
            if(end==sequence.size()){
                continue;
            }
            sum+=sequence[end];
        }
        
        else{
            sum-=sequence[start];
            start++;
            
        }
    }
    
    answer.push_back(resStart);
    answer.push_back(resEnd);
    return answer;
}
