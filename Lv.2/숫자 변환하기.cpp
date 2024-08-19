#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int counter = -1;
void bfs(int x, int y, int n){

    queue<pair<int,int>> q;
    q.push(make_pair(y,0));
    
    while(!q.empty()){
        
        int cur = q.front().first;
        int len = q.front().second;
        q.pop();
        
        if(cur==x){
            counter = len;
            break;
        }

        
        if(cur-n>=x){   
            q.push(make_pair((cur-n),len+1));    
        }
        if(cur%2==0 && cur/2 >= x){  
            q.push(make_pair((cur/2),len+1));
        }
        if(cur%3==0 && cur/3 >= x){
            q.push(make_pair((cur/3),len+1));
                
        }
    }
    
    
}


int solution(int x, int y, int n) {
    int answer = 0;
    
    bfs(x,y,n);
    return counter;
}

