#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0; //결과값 저장할 변수
    string s=""; //3진수 변환값이 거꾸로 저장된 문자열
    
    while(n>0)
    {
        s+=to_string(n%3); //3으로 나눈 나머지값을 문자열에 붙이기
        n/=3;  //n값 3으로 다시 나눠주기
    }
    
    //이로써 s엔 앞뒤 반전된 3진수 변환 문자열이 저장되어있음. 이를 기반으로 다시 10진수로 바꿔주면 됨
    int benchmark=1; //3^0=1
    
    for(int i=s.length()-1;i>=0;i--) //benchmark를 3씩 곱해주면서 answer값 계산
    {
        answer+=benchmark*(s[i]-48);
        benchmark*=3;
    }
    return answer;
}
