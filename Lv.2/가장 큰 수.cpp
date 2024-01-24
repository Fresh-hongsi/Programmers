#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    if(a+b>b+a) // 3 30 이 30 3보다 크므로, 3이 우선순위가 높아 앞에 와야함
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> arr;
    
    for(int i=0;i<numbers.size();i++)
    {
        string temp=to_string(numbers[i]);
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end(),comp);
    
    for(int i=0;i<arr.size();i++)
    {
        answer+=arr[i];
    }
    
    if(answer[0]=='0')
        answer="0";
    
    return answer;
}
