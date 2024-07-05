#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

string invert(int n,int val){ // n: 진법 val: 몇번째 수까지 구해볼 것인지    
    
    char numSet[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string answer ="0"; // 가장 짧은 문자열이라도 0은 포함되는 꼴로 입력받음
    
    for(int i=0;i<=val;i++){
        int cur = i; // 현재 구하고자 하는 수
        string tempString=""; // 현재 구하고자 하는 수를 진수로 변환한 문자열
        
        // cur에 해당하는 숫자를 진수변환
        while(cur>0){
            char temp = numSet[cur%n];
            tempString+=temp;
            cur/=n;
        }     
        
        // 뒤집어야 온전한 진수 변환 문자열 꼴
        reverse(tempString.begin(),tempString.end());
        
        // 그 후에 최종 반환할 문자열에 붙여주기
        answer+=tempString;
    }

    return answer;
    
}

string solution(int n, int t, int m, int p) {
    
    
    string answer = "";
    
    // 최소 t*m값 만큼 미리 출력해놔야 튜브가 말해야 하는 숫자 모두 구할 수 있음
    int val = t*m;
    
    string totalString = invert(n,val);
    
    // totalString에서 튜브가 뽑을 숫자만 구해서 answer에 붙여넣기
    for(int i=0;i<t;i++){
        answer+=totalString[p-1];
        p+=m;
    }
    return answer;
}

// 0 1 1 0 1 1 1 0 0 1 0 1
// 0 1 2 3 4 5 6 7 8 9 A B C D E F 1 0
