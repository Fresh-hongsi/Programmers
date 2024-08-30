#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <string>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> chunk; // 변경된 각 기지국 사이의 거리
    sort(stations.begin(),stations.end()); // 현재 설치된 기지국 오름차순 정렬(기지국 사이의 거리를 구하기 위해)
    int startIdx = 1; // 시작 인덱스
    
    // 현재 기지국이 설치된 곳을 순회하며, 거리 조사
    for(int i=0;i<stations.size();i++){
        
        int k = stations[i]; // 현재 기지국 위치
        
        // 기지국 사이의 거리 조사
        if(k-w-startIdx>0){ 
            chunk.push_back(k-w-startIdx);
        }
        // 거리조사 후 다음 기지국 사이의 거리를 구하기 위해 startIndex 변경
        startIdx = k+w+1;
        
    }
    // 마지막 기지국 다음에 남은 공백이 있다면 거리 조사된 거리 넣어주기
    if(n-startIdx+1>0){
        chunk.push_back(n-startIdx+1);
    }
   
    
    // 각 거리 사이 채울 수 있는 범위
    int size = w+w+1;
    
    for(auto k: chunk){
       
        // 만약 나머지가 없다면, 거리/범위
        if(k%size==0){
            answer+=k/size;
        }
        // 만약 나머지가 있다면, 거리/범위+1
        else{
            answer+=(k/size)+1;
        }
    }

    return answer;
}
