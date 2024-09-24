#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <sstream>
using namespace std;

// xx:yy 형태의 시간을 받아와서, 분의 형태로 만들어주는 메서드
int calculateMinute(string t){
    string hour = "";
    hour+=t[0];
    hour+=t[1];
    int h = stoi(hour);
    
    string minute ="";
    minute+=t[3];
    minute+=t[4];
    int m = stoi(minute);
    
    int result = h*60+m;
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string,int> accumulatedTimePerCar; // 차 번호 : 누적 주차 시간(분)
    map<string,int> carInRecord; // 입차한 차 번호 : 입차 시각(분)
    vector<pair<string,int>> carFees; // 각 차 별 요금
    
    int gibonTime = fees[0]; // 기본 시간
    int gibonFee = fees[1]; // 기본 요금
    int unitTime = fees[2]; // 단위 시간
    int unitFee = fees[3]; // 단위 요금
    
    // 차 별 누적 주차 시간 계산하기
    for(int i=0;i<records.size();i++){
        string s = records[i];
        stringstream ss(s);
        string time; // 입차 시각
        string carNum; // 차 번호
        string cmd; // IN / OUT
        ss>>time>>carNum>>cmd;
        
        if(cmd=="IN"){ // 입차한 시각을 분으로 바꾼 후, 입차 기록을 carInRecord에 넣기
            
            int min = calculateMinute(time);
            carInRecord[carNum]=min;
        }
        
        else if(cmd=="OUT"){ // 입차 기록과 비교하여 누적 입차 시간 계산한 후, accumulatedTimePerCar 업데이트
            
            int min = calculateMinute(time); // 출차 시각
            int accumulatedTime = min-carInRecord[carNum]; // 출차시각 - 입차시각 
            carInRecord.erase(carNum); // 입차기록 지우기
            
            // 이미 전에 오늘 입차-출차한 기록이 있으면, 누적을 위해 업데이트 해야함
            if(accumulatedTimePerCar.find(carNum)!=accumulatedTimePerCar.end()){
                int temp = accumulatedTimePerCar[carNum]; // 전 누적 시간 가져오기
                temp+=accumulatedTime; // 누적 시간 업데이트
                accumulatedTimePerCar[carNum]=temp; 
            }
            else{
                accumulatedTimePerCar[carNum]=accumulatedTime; // 첫 누적 시각 세팅
            }
        }
    }
    
    for(auto k : carInRecord){ // 입차기록 되어있는 것 중 출차 기록 없는 경우, 23:59에 나온 것으로 생각하기
        
        int min = calculateMinute("23:59"); // 출차 시각 임의 지정
        int accumulatedTime = min-carInRecord[k.first]; // 누적 시간 계산
       
        // 이미 전에 오늘 입차-출차한 기록이 있으면, 누적을 위해 업데이트 해야함
        if(accumulatedTimePerCar.find(k.first)!=accumulatedTimePerCar.end()){
                int temp = accumulatedTimePerCar[k.first]; // 전 누적 시간 가져오기
                temp+=accumulatedTime; // 누적 시간 업데이트
                accumulatedTimePerCar[k.first]=temp;
            }
            else{
                accumulatedTimePerCar[k.first]=accumulatedTime; // 첫 누적 시각 세팅
            }
    }
    
    // 누적 시간에 대해, 요금 계산하는 로직
    for(pair<string,int> k : accumulatedTimePerCar){
        string carNum = k.first; // 차량 번호
        int min = k.second; // 누적 시간
        
        // 기본 시간 안에서 주차를 했다면
        if(min<=gibonTime){
            carFees.push_back(make_pair(carNum,gibonFee));
        }
        // 기본 시간을 초과한 경우
        else{
            int fee = gibonFee;
            min-=gibonTime;
            
            int chugaTime = 0;
            if(min%unitTime!=0){
                chugaTime=min/unitTime+1;
            }
            else{
                chugaTime = min/unitTime;
            }
            carFees.push_back(make_pair(carNum, fee+chugaTime*unitFee));
        }
    }
    
    // 차 번호로 오름차순 정렬
    sort(carFees.begin(),carFees.end());
    
    // 정답 도출
    for(auto k : carFees){
        answer.push_back(k.second);
    }
    return answer;
}
