#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(),dungeons.end()); // 순열을 쓰기 위해 정렬 해주기
    
    do{
        int curK = k; // 초기 k값 복사
        int counter = 0;
        
        for(int i=0;i<dungeons.size();i++){
            if(curK>=dungeons[i][0]){
                curK-=dungeons[i][1];
                counter++;
            }
            
            else{
                break;
            }
        }
        
        if(counter>=answer){
            answer=counter;
        }
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    return answer;
}
