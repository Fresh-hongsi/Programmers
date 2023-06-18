#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) //알파벳이라면
        {
            
            if(s[i]+n>'z' && s[i]>='a' && s[i]<='z') //소문자에서 오버플로우 발생한경우
            {
                answer+=s[i]+n-'z'+'a'-1;
                
            }
            else if(s[i]+n>'Z' && s[i]<='Z' && s[i]>='A') //대문자에서 오버플로우 발생한경우
            {
                answer+=s[i]+n-'Z'+'A'-1;
            }
            
            
            else //문자이지만 오버플로우가 안생긴 경우
            {
                answer+=s[i]+n;     
            }
               
        }
        
        else //공백인경우
        {
            answer+=s[i];
        }
    }
    return answer;
}
