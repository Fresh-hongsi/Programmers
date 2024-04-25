// #include <string>
// #include <vector>
// #include <deque>
// #include <algorithm>

// using namespace std;

// // 덱 이용
// int solution(vector<int> people, int limit) {
    
//     int answer = 0;
//     deque<int> dq;
    
//     sort(people.begin(), people.end()); // 오름차순 정렬
    
//     for(int i=0;i<people.size(); i++) // 덱에 오름차순으로 넣어주기
//     {
//         dq.push_back(people[i]);
//     }
    
//     // 덱이 비지 않을 때까지 반복
//     while(!dq.empty())
//     {
//         // 덱에 원소가 두개 이상 남아있고, 가장 앞의 원소와 가장 뒤의 원소의 합이 limit보다 같거나 작으면,
//         // 가장 앞, 가장 뒤 원소를 제거하고, answer값 1 증가시킴
//         if((dq.begin()+1 != dq.end()) && dq.front()+dq.back()<=limit)
//         {
//             dq.pop_front();
//             dq.pop_back();
//             answer++;
//         }
//         // 만약 원소가 하나 남아있거나, 가장 앞, 가장 뒤 원소의 합이 limit보다 크다면,
//         // 가장 뒤에 있는 것만 제거하고 answer값 1 증가시킴
//         else
//         {
//             dq.pop_back();
//             answer++;
//         }
//     }
    
//     return answer;


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    
    // 그리디 - 가장 무거운 사람과 가장 가벼운 사람 같이 태우기 시도
    // 80 70 40 20 10 10 10
    
    sort(people.begin(),people.end(),greater<int>()); // 내림차순 정렬
   
    int i = 0; // 현재 시점 가장 무거운 사람
    int j = people.size()-1; // 현재 시점 가장 가벼운 사람
    
    while(i<=j){
        
        int sum = people[i]; // 일단 무거운 사람 태우기
        if(sum+people[j]<=limit){ // 만약 가벼운 사람도 태울 수 있으면
            answer++; // 보트 탑승
            i++; // 다음 무거운 사람 찾기
            j--; // 다음 가벼운 사람 찾기
        }
        else{ // 만약 가벼운 사람을 같이 태울 수 없으면
            answer++; // 무거운 사람만 보트 태우기
            i++; // 다음 무거운 사람 찾기
        }
    }
    
    return answer;
    
    
    
}
// }
