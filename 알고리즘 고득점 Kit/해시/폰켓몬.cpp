#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    
    for(int i=0;i<nums.size();i++){
        
        if(m.find(nums[i])!=m.end()){
            m[nums[i]]++;
        }
        
        else{
            m.insert(make_pair(nums[i],1));
        }
    }
                     
    answer = min(nums.size()/2, m.size());
    
    return answer;
}
