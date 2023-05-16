using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long temp=0;
    for(int i=1;i<=count;i++)
    {
        temp+=i*price;
    }
    
    answer=money-temp;
    
    if(answer>0)
    {
        answer=0;
    }

    else
    {
        answer=answer*-1;
    }
    return answer;
}
