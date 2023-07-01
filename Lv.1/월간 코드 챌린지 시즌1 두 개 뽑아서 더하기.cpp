#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size()-1;i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            bool flag=false;
            int temp=numbers[i]+numbers[j];
            for(int k=0;k<answer.size();k++)
            {
                if(temp==answer[k])
                {
                    flag=true;
                    break;
                }
                
            }
            if(flag==false)
            {
                answer.push_back(temp);
                sort(answer.begin(),answer.end());    
            }
            
        }
    }
    return answer;
}
