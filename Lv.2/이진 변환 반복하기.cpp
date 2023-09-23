#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroErasedNum=0; // 제거된 0의 개수
    int conversionNum=1; // 진번 변환 횟수
    string stringSetter=s; // 진법 변환을 할때마다 다시 새로운 문자열로 세팅됨
    string tempString=""; // 각 진법 변환시마다 0을 지운 결과가 저장되는 문자열
    
    while(1)
    {
        // 0을 제거하여 tempString에 저장
        for(int i=0;i<stringSetter.length();i++)
        {
            if(stringSetter[i]=='0')
            {
                zeroErasedNum++;
            }
            else
            {
                tempString+="1";
            }
        }
    
        
        int length = tempString.length();
        string conversionToBinaryReverse=""; // 거꾸로 된 이진법 변환 문자열
        
        // 거꾸로 된 이진변환 문자열 구하기
        while(length!=0)
        {
            if(length%2==0)
            {
                conversionToBinaryReverse+="0";
                length/=2;
            }
            else{
                conversionToBinaryReverse+="1";
                length/=2;
            }
        
        }
        
        // 다시 거꾸로 해야 정상적인 2진법 변환
        reverse(conversionToBinaryReverse.begin(), conversionToBinaryReverse.end()); 
    
        // 만약 1이 아니면 다시 시도
        if(conversionToBinaryReverse!="1")
        {
            stringSetter=conversionToBinaryReverse;
            tempString="";
            conversionNum++;
            continue;
        }
        else
        {
            break;
        }
    }
    
    
    answer.push_back(conversionNum);
    answer.push_back(zeroErasedNum);
    return answer;
}
