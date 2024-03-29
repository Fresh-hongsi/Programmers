#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
   
    
    int result = -1;
    sort(dungeons.begin(),dungeons.end()); //next_permutation을 쓰기 위해 정렬
    
    do{
         int kTemp = k;  // 순열이 바뀔 때마다 기존의 k값을 복사해 사용할 임시 k값 변수
         int cur = 0; // 현재 순열에서 던전을 최대 몇개 갈 수 있는 지 저장할 변수
        
         for(int i=0;i<dungeons.size();i++){ // 던전을 순회
            
             if(kTemp>=dungeons[i][0]){ // 만약 던전에 입장 가능하면
                 cur++; // 갈 수 있는 던전 개수 +1
                 kTemp-=dungeons[i][1]; // 소모 피로도 처리
             }
             
             else{ // 더이상 던전 입장이 불가할 경우
                 break; // 반복문 탈출
             }
             
         }
        
         // 만약 현재 갈 수 있는 던전 개수가 기존의 최대 개수보다 크다면, 업데이트
         if(cur>result){
              result = cur;
         }
    } while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return result;
}
