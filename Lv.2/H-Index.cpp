#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<int> citations) {
    int curH = 0;
    
    
    while(1){
        int count = 0;
        for(int i=0;i<citations.size();i++){
            if(curH<=citations[i]){
                count++;
            }
        }
        
        if(count>=curH){
            curH++;
        }
        else{
            break;
        }
    }
    
    return curH-1;
}
