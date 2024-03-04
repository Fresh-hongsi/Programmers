#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(int n, int a, int b)
{

    int round = 1;
    int answer = 0;
    int t1 = min(a-1,b-1);
    int t2 = max(a-1,b-1);

    
    while(1)
    {
       
        if(t1%2==0 && t2%2==1 && t1+1==t2){
            answer = round;
            break;
        }
        
        else{
            t1/=2;
            t2/=2;
            round++;
        }
    }
    

    
    return answer;
}
