#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int l=p.length();
    for(int i=0;i<t.length()-(l-1);i++)
    {
        string temp;
        for(int j=i;j<i+l;j++)
        {
            temp.push_back(t[j]);
        }
        
        if(temp<=p)
        {
            answer++;
        }
    }
    return answer;
}
