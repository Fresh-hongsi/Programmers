#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    // 기본 벽 세팅 -> 칠해야 할 벽은 false처리
    bool arr[200001];
    for(int i=0;i<200001;i++){
        arr[i]=true;
    }
    for(int i=0;i<section.size();i++){
        arr[section[i]-1]=false;
    }
    
    // 칠해야 할 벽이 보이면, 롤러로 바로 칠하기
    for(int i=0;i<n;i++){
        if(arr[i]==true){
           
            continue;
        }
        else{

            for(int j=i;j<i+m;j++){
                arr[j]=true;                
            }
           
            answer++;
            
        }

    }
    return answer;
}
