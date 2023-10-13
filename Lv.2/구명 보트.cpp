#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 덱 이용
int solution(vector<int> people, int limit) {
    
    int answer = 0;
    deque<int> dq;
    
    sort(people.begin(), people.end()); // 오름차순 정렬
    
    for(int i=0;i<people.size(); i++) // 덱에 오름차순으로 넣어주기
    {
        dq.push_back(people[i]);
    }
    
    // 덱이 비지 않을 때까지 반복
    while(!dq.empty())
    {
        // 덱에 원소가 두개 이상 남아있고, 가장 앞의 원소와 가장 뒤의 원소의 합이 limit보다 같거나 작으면,
        // 가장 앞, 가장 뒤 원소를 제거하고, answer값 1 증가시킴
        if((dq.begin()+1 != dq.end()) && dq.front()+dq.back()<=limit)
        {
            dq.pop_front();
            dq.pop_back();
            answer++;
        }
        // 만약 원소가 하나 남아있거나, 가장 앞, 가장 뒤 원소의 합이 limit보다 크다면,
        // 가장 뒤에 있는 것만 제거하고 answer값 1 증가시킴
        else
        {
            dq.pop_back();
            answer++;
        }
    }
    
    return answer;
}
