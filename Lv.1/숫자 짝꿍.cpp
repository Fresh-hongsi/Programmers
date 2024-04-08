#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<char,int> mapX; // X 문자열에 있는 각 숫자가 몇개인지 확인할 map
    map<char,int> mapY; // Y 문자열에 있는 각 숫자가 몇개인지 확인할 map
    
    // 초기에 mapX, mapY에 대해 0개로 세팅
    for(int i=0;i<9;i++){
        mapX[i]=0;
        mapY[i]=0;
    }
    
    // X 문자열 순회하며 각 숫자 개수 몇개인지 저장
    for(int i=0;i<X.length();i++){
        mapX[(X[i]-'0')]++;
    }
    
    // Y 문자열 순회하며 각 숫자 개수 몇개인지 저장
    for(int i=0;i<Y.length();i++){
        mapY[(Y[i]-'0')]++;
    }
    
    // 0~9까지 mapX, mapY 비교하며 각 숫자에 대한 공통개수만큼 answer에 push
    for(int i=0;i<10;i++){
        int common = 0;
        common = min(mapX[i],mapY[i]);
        
        for(int j=0;j<common;j++){
            answer+=to_string(i);
        }
    }
    
    // 만약 X, Y에 공통 숫자가 없었다면 -1 
    if(answer==""){
        answer="-1";
        return answer;
    }
   
    // 그게 아니라면, 내림차순 정렬
    sort(answer.begin(),answer.end(),greater<char>());
    
    // 그러나 answer이 0으로 시작한다면 0이므로 00~~ 이 아닌 0으로 반환해야함
    if(answer[0]=='0'){
        answer="0";
    }
    
    
    
    return answer;
}

// 0: 2    0: 0
// 1: 1    1: 0
    
