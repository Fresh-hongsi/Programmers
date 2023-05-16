#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    int count=0;
    
    if((s.length()==4 || s.length()==6))
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                count++;
            }
        
            else
            {
                answer=false;
                break;
            }
        }
    
        if(count==s.length())
        {
            answer=true;
        }

    }
    else
    {
        answer=false;
    }
    
    return answer;
}
