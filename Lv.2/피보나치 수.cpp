#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr(100001,0);
    
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        arr[i]=(((arr[i-1]%1234567)+(arr[i-2]%1234567))%1234567);
    }
    
    answer= arr[n];
    return answer;
}
