#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n!=0) // n이 0이 될 때까지 수를 작게 나누기
    {
        if(n%2==1) // 나머지가 1이면 순간이동 전 값 + 1 해준 게 최소값임
        {
            ans++;
            n/=2;
        }
        else // 나머지가 0이면 순간이동 전 값이 최소값임
        {
            n/=2;
        }
    }
   
    return ans;
}
