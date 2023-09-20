#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    bool flag=false; // 공백 문자열을 지나면 true로 바뀜
    
    
    for(int i=0;i<s.length();i++)
    {
        if(i==0) // 첫번째 인덱스에서도 소문자이면, 대문자로 바꿔줘야함
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i]-=32; // 대문자로 변환
            }
            flag=false; // 공백문자 아니므로
            continue;
        }
        
        if(s[i]==' ') // 공백 문자라면
        {
            flag=true; // 공백문자임을 표시
            continue;
        }
        
        if(flag==true) // 공백을 지나고, 숫자또는 문자가 들어있다면
        {
            if(s[i]>='a' && s[i]<='z') // 만약 소문자라면 
            {
                s[i]-=32; // 대문자로 변환해야함
            }
            flag=false; // 공백문자 아니므로
            continue;
        }
        
        else // 이외의 경우는 공백도 아니고, 첫번째 인덱스도 아니고, 공백 이후 첫번째 문자도 아님 -> 모두 소문자화시키면 됨
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]+=32;
                flag=false;
            }
        }
    }
    string answer = "";
    answer=s;
    return answer;
}
