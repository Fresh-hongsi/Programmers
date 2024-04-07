#include <string>
#include <vector>
#include <map>
#include <regex>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    
    for(int i=0;i<babbling.size();i++){
        string s = babbling[i];
        s = regex_replace(s,regex("aya"),"1");
        s = regex_replace(s,regex("ye"),"2");
        s = regex_replace(s,regex("woo"),"3");
        s = regex_replace(s,regex("ma"),"4");
        
        bool flag = true;
        // 같은 거 연속되면 발음 불가
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                flag=false;
                break;
            }
            
        }
        
        // 1,2,3,4가 아닌 게 있으면 발음 불가
        for(int i=0;i<s.length();i++){
            if(s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4'){
                flag=false;
                break;
            }
        }
        
        if(flag==true){
            answer++;
        }
        cout<<s<<'\n';

    }
    

    return answer;
}
