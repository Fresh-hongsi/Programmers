#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
    
    queue<int> onBridge; // 다리 위에 있는 트럭 큐
    queue<int> outBridge; // 다리로부터 빠져 나온 트럭 큐
    int size = truck_weights.size();
    
    int onBridgeWeight = 0; // 다리 위에 있는 트럭 무게의 합
    
     
    while(outBridge.size()<size){
        
        answer++; // 시간 추가
        
        // 다리 위의 트럭이 꽉 찬 경우
        // 가장 앞에 있는 트럭이 있는 경우(무게가 0이상) onBridge 큐에서 제거한 후 outBridge로 이동
        // 트럭이 없는 경우(무게를 0으로 표시) onBridge 큐에서 제거만 하기
        
        if(onBridge.size()==bridge_length){
            
            int front = onBridge.front();
            onBridge.pop();
            onBridgeWeight-=front;
            
            if(front!=0){    
                
                outBridge.push(front);
            }
        }
        
        // 다리에 트럭 놓기 - 트럭이 들어갈 수 없으면 0으로 설정해 onBridge큐에 추가
        //                  트럭이 들어갈 수 있으면 트럭을 다리에 놓고, truck_weights의 첫번째 원소 제거
        if(truck_weights.size()>0){
            if((onBridgeWeight+truck_weights[0])<=weight){
                onBridgeWeight+=truck_weights[0];
                onBridge.push(truck_weights[0]);
                truck_weights.erase(truck_weights.begin());
                
            }
            
            else{
                onBridgeWeight+=0;
                onBridge.push(0);
            }
        }
        
        else{
            onBridgeWeight+=0;
            onBridge.push(0);
        }
        
        
    }
    
    
    
    return answer;
}
