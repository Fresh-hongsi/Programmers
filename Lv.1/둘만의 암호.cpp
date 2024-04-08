#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map<char,int> m; // skip을 제외한 각 문자가 어느 인덱스에 위치하는 지 확인하기 위함
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // alphabet 문자열에서 skip에 포함된 각 문자를 제외시킴
    for(int i=0;i<skip.length();i++){
        char cur = skip[i];
        alphabet.erase(remove(alphabet.begin(),alphabet.end(),cur),alphabet.end()); 
    }
    
    // skip에 포함되지 않은 각 문자가 어느 인덱스에 있는 지 map에 저장
    for(int i=0;i<alphabet.length();i++){
        m[alphabet[i]]=i;
    }
    
    // 제한사항을 고려하여 (컨베이어벨트처럼 z를 넘어가는 index도 계산할 수 있도록) alphabet문자열 조절
    alphabet+=alphabet;
    alphabet+=alphabet;
    
    // s의 각 문자에 대해, 시작 위치를 찾고, index를 더했을 때의 문자를 찾아 answer에 추가
    for(int i=0;i<s.length();i++){
        
        int idx=m[s[i]];
        idx+=index;
        char x = alphabet[idx];
        answer+=(x);
    }
    
    return answer;
}

