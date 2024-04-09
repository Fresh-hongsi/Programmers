#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int bandTime = bandage[0]; // 밴드 시전 시간
    int healPerSecond = bandage[1]; // 초당 회복량
    int bonusHeal = bandage[2]; // 추가 회복량
    int continuedBanding = -2; // 연속 밴딩 성공 시간
    
    int curHealth = health; // 현재 체력
    int maxHealth = health; // 최대 체력
    
    int curTime = -1; // 현재 시간
    
    queue<pair<int,int>> q; // 공격 받은 시간, 공격 피해량 저장할 큐
    for(int i=0;i<attacks.size();i++){
        q.push(make_pair(attacks[i][0],attacks[i][1]));
    }
    
    
    while(1){
        
        if(q.size()<1){ // 큐가 빈 경우 현재 체력 반환
            answer=curHealth;
            break;
        }
        
        if(q.front().first==curTime){ // 공격이 이루어지는 타이밍인 경우
            continuedBanding=0; // 연속 밴딩 성공 초기화
            curHealth-=q.front().second; // 체력 삭감
            q.pop();
            if(curHealth<=0){ // 체력이 바닥난 경우
                answer=-1; 
                break;
            }
        }
        else{ // 공격이 이루어지지 않는 경우
            
            // 연속 밴딩 성공 증가시킴
            continuedBanding++;
            
            // 연속 밴딩 성공이 시전 시간에 도달한 경우면 보너스까지 추가하고, 연속 성공시간 0으로 초기화
            if(continuedBanding==bandTime){
                curHealth+=healPerSecond;
                curHealth+=bonusHeal;
                continuedBanding=0;
            }
            else if(continuedBanding<bandTime){// 연속 밴딩 성공이 시전 시간에 도달하지 못했으면 기본 체력 추가
                curHealth+=healPerSecond;
            }
            
            // 근데 체력이 최대값을 넘었으면 최대로 바꿔주기
            if(curHealth>maxHealth){
                curHealth=maxHealth;
            }
        }
        
        cout<<"health:"<<curHealth<<" curTime: "<<curTime<<" continue: "<<continuedBanding<<'\n';
        curTime++; // 시간 증가
        
        
        
    }
    return answer;
}
