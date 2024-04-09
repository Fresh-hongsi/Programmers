#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    // 시작 위치 찾고, 그 위치는 0 표시 하기
    int startR = 0; // 시작 위치 행
    int startC = 0; // 시작 위치 열
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].length();j++){
            if(park[i][j]=='S'){
                startR = i;
                startC = j;
                break;
            }
            
        }
    }
    
    
    int maxR = park.size()-1; // 공원에서 아래로 갈 수 있는 최대 좌표
    int maxC = park[0].length()-1; // 공원에서 우측으로 갈 수 있는 최대 좌표
    
    int curR = startR;
    int curC = startC;
    
    // 로봇 강아지 이동 수행
    for(int i=0;i<routes.size();i++){
        
        stringstream ss(routes[i]);
        char direction;
        int moveSpan;
        ss>>direction>>moveSpan;
        
        if(direction=='E'){
            int temp = curC; 
            bool flag = true;
            for(int i=curC;i<=curC+moveSpan;i++){ // 가보기
                if(i>maxC || park[curR][i]=='X'){
                    
                    flag = false; 
                    break;
                }
            }
            if(flag == true){
                curC+=moveSpan;
            }
            
        }else if(direction=='W'){
            int temp = curC; 
            bool flag = true;
            for(int i=curC;i>=curC-moveSpan;i--){ // 가보기
                if(i<0 || park[curR][i]=='X'){
                    
                    flag = false; 
                    break;
                }
            }
            if(flag == true){
                curC-=moveSpan;
            }
            
        }else if(direction=='S'){
            int temp = curR; 
            bool flag = true;
            for(int i=curR;i<=curR+moveSpan;i++){ // 가보기
                if(i>maxR || park[i][curC]=='X'){
                    
                    flag = false; 
                    break;
                }
            }
            if(flag == true){
                curR+=moveSpan;
            }            
        }else if(direction=='N'){
            int temp = curR; 
            bool flag = true;
            for(int i=curR;i>=curR-moveSpan;i--){ // 가보기
                if(i<0 || park[i][curC]=='X'){
                    
                    flag = false; 
                    break;
                }
            }
            if(flag == true){
                curR-=moveSpan;
            }               
        }
        
        
    }
    
    answer.push_back(curR);
    answer.push_back(curC);
    
    
    return answer;
}

// 0 0 0
// 0 0 0
// 0 x 0
// 0 0 0
