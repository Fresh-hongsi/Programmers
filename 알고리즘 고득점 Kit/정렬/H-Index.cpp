#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
   
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i=0;i<10001;i++){
        
        int overH = 0;
        
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=i){
                overH++;
            }
        }
        
        
        if(i>overH){
            answer=i-1;
            break;
        }
        
        
    }
    
    return answer;
}
