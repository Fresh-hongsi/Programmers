#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string cur="";
    string next="";
    int cur1Count=0; // 처음 들어온 n값에 대한 1의 개수
    int next1Count=0; // 앞으로 계속 n값을 증가시켜보면서 1값을 count할 변수
    int temp=n; // 처음엔 temp변수에 n을 세팅
    
    // 처음 수 n에 대해서 1의 갯수 count하기
    while(temp>0)
    {
        if(temp%2==0)
        {
            cur+='0';
        }
        else
        {
            cur+='1';
            cur1Count++;
        }
        temp/=2;
    }
    
    // n값을 1씩 증가시켜보면서 해당 수에 1이 몇개 있는지 count하기
    while(1)
    {
        n+=1;
        temp=n;
        next1Count=0;
        
        while(temp>0)
        {
            if(temp%2==0)
            {
                next+='0';
            }
            else
            {
                next+='1';
                next1Count++;
            }
            temp/=2;
        }
        
        // 처음 들어온 수의 1개수와 1씩 증가시켜보면서 count한 1의 갯수가 같다면 while문 종료
        if(cur1Count==next1Count)
        {
            answer=n;
            break;
        }
        
        
    }
    
    
    return answer;
}
