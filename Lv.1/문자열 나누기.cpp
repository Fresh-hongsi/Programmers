#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {

    int answer = 0;
    int xCount = 1;
    int yCount = 0;
    char x = s[0];

    for(int i=1;i<s.length();i++){
        
        if(x==s[i]){
            xCount++;
        }
        else{
            yCount++;
        }
        
        if(xCount==yCount){
            x=s[i+1];
            cout<<x;
            xCount=0;
            yCount=0;
            answer++;
        }
    }
    
    if(xCount>0){
        answer++;
    }

    return answer;
}
