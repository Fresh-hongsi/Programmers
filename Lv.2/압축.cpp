#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string,int> m;
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string temp = "";
    for(int i=0;i<26;i++){
        m[temp+str[i]]=i+1;
        temp="";
    }
    // 아래의 과정을 위 코드로 대체
    // m["A"]=1;   m["B"]=2;   m["C"]=3;
    // m["D"]=4;   m["E"]=5;   m["F"]=6;
    // m["G"]=7;   m["H"]=8;   m["I"]=9;
    // m["J"]=10;   m["K"]=11;   m["L"]=12;
    // m["M"]=13;   m["N"]=14;   m["O"]=15;
    // m["P"]=16;   m["Q"]=17;   m["R"]=18;
    // m["S"]=19;   m["T"]=20;   m["U"]=21;
    // m["V"]=22;   m["W"]=23;   m["X"]=24;   
    // m["Y"]=25;   m["Z"]=26;
    
    int idxNum = 27; // 새롭게 등재될 문자열의 번호
    int curIdx = 0; // 현재 참조하고 있는 인덱스값
    
    string w = "";
    w+=(msg[0]); // 첫번째 입력 확인
    
    while(curIdx<msg.length()){
        if(m.find(w)!=m.end()){ // 현재 입력(w)가 등재되어있다면, 다음 인덱스 문자 더 넣고 찾기 시도
            
            if(curIdx==msg.length()-1){ // 입력이 끝에 다다른경우 반복문 종료
                 break;
            }
            curIdx++;
            w+=msg[curIdx];
            continue;
        }
        else{ // 현재 입력이 사전에서 더이상 찾을 수 없다면 가장 마지막에 찾을 수 있었던 것을 출력하고, 현재 입력을 사전에 추가
            int wLength = w.length();
            string wCopy = w;
            wCopy.erase(wCopy.begin()+wLength-1); // 가장 최근에 찾을 수 있던 문자열
            answer.push_back(m[wCopy]); // 출력
            m[w]=idxNum++; // 사전 추가
            w=""; // 현재 입력을 다시 세팅
            w+=msg[curIdx];
            //cout<<curIdx<<' ';
        }
    }
    
    // 마지막 문자열을 출력하기
    answer.push_back(m[w]);
    return answer;
}
