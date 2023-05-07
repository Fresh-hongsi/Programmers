#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string s=to_string(x);
    int totalSum=0;
    for(int i=0;i<s.length();i++)
    {
        totalSum+=s[i]-48;
    }
    
    if(x%totalSum==0)
    {
        answer=true;
    }
    else
    {
        answer=false;
    }
    return answer;
}
