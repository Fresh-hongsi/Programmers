#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    
    string s=to_string(n);
    vector<int> answer;
    for(int i=0;i<s.length();i++)
    {
        answer.push_back(s[i]-48);
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}
