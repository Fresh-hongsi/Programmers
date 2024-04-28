#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    vector<int> answer;
    
    for(long long i = left; i<=right;i++){
        long long quotient = i/n;
        long long remainder = i%n;
        
        if(remainder>=quotient){
            answer.push_back(remainder+1);
        }
        else{
            answer.push_back(quotient+1);
        }
        
    }
    
    

    
    return answer;
}

//   // 0 1 2 3

// 0 // 1 2 3 4
// 1 // 2 2 3 4
// 2 // 3 3 3 4
// 3 // 4 4 4 4
