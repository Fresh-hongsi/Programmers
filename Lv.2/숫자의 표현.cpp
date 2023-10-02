#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++) // 1부터 차례대로 기준점 숫자 넣어보기
    {
        bool flag=true; //while문 실행 조건
        int temp=i; // 기준점 숫자를 temo변수에 별도로 세팅
        int sum=temp; // 각 for문 실행 때마다 sum의 시작값은 i값으로 세팅
        
        while(flag)
        {
            if(sum==n) // 만족할 경우
            {
                flag=false;
                answer++;
                break;
            }
            
            if(sum<n) // n보다 sum이 작을 경우엔 더 더해봐야함
            {
                temp+=1;
                sum+=temp;
    
            }
            if(sum>n) // n보다 sum이 클 경우엔 더 while문을 돌 필요가 x
            {
                break;
            }
                    
        }
    }
    return answer;
}
