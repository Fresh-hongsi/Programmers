#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string,map<string,int>> giftBoard; // 게시물 주고 받은 현황 관리판
    // m -> m:0 r:0 f:2 n:0
    // r -> m:3 r:0 f:0 n:0
    // f -> m:1 r:1 f:0 n:0
    // n -> m:1 r:0 f:0 n:0
    
    
    map<string,int> giftIndex; // 각 멤버별 선물지수
    // m: -3
    // r: 2
    // f: 0
    // n: 1
    
    
    // 멤버에 대해 선물지수 map과 현황관리판 map 초기화
    for(int i=0;i<friends.size();i++){
        giftIndex[friends[i]]=0;
        
        for(int j=0;j<friends.size();j++){
            giftBoard[friends[i]][friends[j]]=0; // 이 부분 중요! 모든 member와 주고 받은 내역을 0으로 초기화(2차원 행렬처럼)
        }
        
    }
    
    // 선물 지수표, 현황 관리판 업로드
    for(int i=0;i<gifts.size();i++){
        string from=""; // 주는 사람
        string to=""; // 받는 사람
        stringstream ss(gifts[i]);
        ss>>from>>to;
        
        giftBoard[from][to]++; // 게시판에 준 사람, 받은사람 관계 등록
        giftIndex[from]++; // 준 사람은 선물지수 증가
        giftIndex[to]--; // 받은 사람은 선물지수 감소
        
    }
    
    // 각 사람 별 받을 선물 개수 계산
    vector<int> expectedGiftNum; // 사람 별 다음달에 받을 선물 개수 저장할 벡터 
    for(int i=0;i<friends.size();i++){
        int count = 0;
        string curFriend = friends[i]; 
        
        for(auto k : giftBoard[curFriend]){
            
            string target = k.first; // curFriend 기준 선물을 준 사람
            
            // target 사람에게 받은 것보다 많이 줬다면 +1 추가
            if(k.second>giftBoard[target][curFriend]){
                count++;
            }
            
            // 만약 주고받지 않았거나, 서로 주고받은 수가 같다면 -> 선물 지수 비교 후 +1
            else if(k.second==giftBoard[target][curFriend]){
                if(giftIndex[curFriend]>giftIndex[target]){
                    count++;
                }
            } 
            
        }
        expectedGiftNum.push_back(count);
        
        
    }
    
    answer = *max_element(expectedGiftNum.begin(),expectedGiftNum.end());
    
    return answer;
}

