#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <limits.h>
using namespace std;

// 아이디어 참신함!
vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(s/n<1){
        answer.push_back(-1);
    }
    
    else{
        
        int partition = s/n;
        int remainder = s%n;
        int counter = 0;
        
        for(int i=0;i<remainder;i++){
            answer.push_back(partition+1);
            counter++;
        }
        
        for(int i=counter+1;i<=n;i++){
            answer.push_back(partition);
        } 
        
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}


// 11 3 - partition:3  remainder:2
// 3 4 4
    
    
