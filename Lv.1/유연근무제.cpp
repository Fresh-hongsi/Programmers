#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

    
bool arrivedWithinPlannedTime(int plannedArrivalTime, int actualArrivalTime){
    int pAHour = plannedArrivalTime/100;
    int pAMinute = plannedArrivalTime%100;
    int aAHour = actualArrivalTime/100;
    int aAMinute = actualArrivalTime%100;
    
    int calculatedPlannedArrivalTime = pAHour*60+pAMinute;
    int calculatedActualArrivalTime = aAHour*60+aAMinute;
    
    if(calculatedPlannedArrivalTime-calculatedActualArrivalTime <-10){
        return false;
    }
    return true;
    
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0;i<schedules.size();i++){ // 직원 번호 순회
        bool successFlag = true; 
        
        for(int day=0; day<7; day++){ 
            
            int currentday = (day+startday-1)%7; // 요일 계산
            if(currentday==5 || currentday==6){  // 토 또는 일의 경우는 판정 기준 제외
                
                continue;
            }
            
            else if(!arrivedWithinPlannedTime(schedules[i],timelogs[i][day]) && currentday>=0 && currentday<=4){ // 월~금요일이고, 이벤트를 실패할 경우
                successFlag = false;
                break;
            }
            
            else{
                // no statement
            }
        }
        
        if(successFlag==true){
            cout<<i<<'\n';
            answer++;
        }
    }
    return answer;
}
