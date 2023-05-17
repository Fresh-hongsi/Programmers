#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int minimum=min(n,m); //더 작은 수 찾기
    int gcd=0;
    int lcm=0;
    for(int i=1;i<=minimum;i++)
    {
        if(n%i==0 && m%i==0)
        {
            gcd=i;
        }
    }
    
    lcm=gcd*(n/gcd)*(m/gcd);
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}
