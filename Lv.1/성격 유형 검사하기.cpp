#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
   
    map<char,int> m;
    m['R']=0; m['T']=0;
    m['C']=0; m['F']=0;
    m['J']=0; m['M']=0;
    m['A']=0; m['N']=0;
    
    for(int i=0;i<survey.size();i++){
        string curSurvey = survey[i];
        int curChoice = choices[i];
        
        if(curChoice<4){
            m[curSurvey[0]]+=(4-curChoice);
        }else if(curChoice>4){
            m[curSurvey[1]]+=(curChoice-4);
        }else{
            continue;
        }
    }
    m['R'] >= m['T'] ? answer+="R" : answer+="T";
    m['C'] >= m['F'] ? answer+="C" : answer+="F";
    m['J'] >= m['M'] ? answer+="J" : answer+="M";
    m['A'] >= m['N'] ? answer+="A" : answer+="N";
    

    
    return answer;
}
