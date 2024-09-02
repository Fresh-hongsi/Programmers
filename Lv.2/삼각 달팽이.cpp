#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <limits.h>
using namespace std;

vector<int> solution(int n) {
    
    int startSize = n; // 최초 배열의 가로, 세로 길이
    vector<vector<int>> arr(n,vector<int>(n,0)); // 이차원 임시 벡터
    
    int counter = 0; // 현재 옵션 (아래, 오른쪽, 대각 중 하나를 관리할 변수)
    int k = 1; // 각 arr에 어떤 수가 들어갈 지 추첮
    vector<int> answer;
    
    int r = -1; // 계산 시작할 행값
    int c = 0; // 계산 시작할 열값
    
    while(n>0){
        if(counter==0){ // 아래 방향
            counter++; // 계산 옵션 변경
            
            for(int i=0;i<n;i++){
                arr[++r][c]=k++;
            }
            
            n--; // 크기 줄이기
            continue;
        
        }else if(counter==1){ // 오른쪽 방향
            counter++; // 계산 옵션 변경
            
            for(int i=0;i<n;i++){
                arr[r][++c]=k++;
            }
             
            n--; // 크기 줄이기
            continue;
            
        }else{ //대각 오름 방향
            counter = 0; // 계산 옵션 변경
            
            for(int i=0;i<n;i++){
                arr[--r][--c]=k++;
            }
            n--; // 크기 줄이기
            continue;
        }
    }
    
    // 출력
    for(int i=0;i<startSize;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    
    return answer;
}
