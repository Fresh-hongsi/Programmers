#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int,vector<int>,less<int>> pq; // 내림차순 우선순위큐
    
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    while(1){
        int top = pq.top();
        if(top==0 || n==0){
            break;
        }
        else{
            n--;
            pq.pop();
            pq.push(top-1);
        }
    }
    
    while(!pq.empty()){
        answer+=(int)pow(pq.top(),2);
        pq.pop();
    }
    return answer;
}
