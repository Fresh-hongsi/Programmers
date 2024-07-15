#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int cnt = 0;
string target = "";
char arr[5]={'A','E','I','O','U'};
bool flag = false;

void dfs(string cur){
    
    if(cur==target){
        flag=true;
        return;
        
    }
    
    if(cur.length()==5){
        
            return;
        
    }
    
    
    for(int i=0;i<5;i++){
        
        cnt++;
        dfs(cur+arr[i]);
        if(flag==true){
            return;
        }

           
    }
}
    
    
    
    

int solution(string word) {
    
    int answer = 0;
    target=word;
    dfs("");
    answer=cnt;
    return answer;
}
