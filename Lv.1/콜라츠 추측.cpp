#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long answer = 0;
    long n=num;
    for(long i=1;i<=500;i++)
    {
        if(n==1)
        {
          break;   
        }
        
        else
        {
            if(n%2==0)
            {
                n/=2;
                answer++;
            }
            
            else
            {
                n=n*3+1;
                answer++;
            }
        }
    }
    
    if(n!=1)
    {
        answer= -1;
    }
    
    return answer;
}
