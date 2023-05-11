#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int temp: arr)
    {
        if(temp%divisor==0)
        {
            answer.push_back(temp);
        }
    }
    
    if(answer.size()>=1)
    {
      sort(answer.begin(),answer.end());
      
    }
    
    else
    {
        answer.push_back(-1);
    }
    
    return answer;
}
