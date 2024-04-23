// #include <string>
// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;

// // 두 개의 lcm을 구한 후, 스택에 넣어주는 과정을 반복함으로써 최종 lcm을 구하는 로직

// int solution(vector<int> arr) {
    
//     stack<int> st; // 스택 선언
    
//     for(int i=0;i<arr.size();i++) // 스택에 담아줌
//     {
//         st.push(arr[i]);
//     }
    
//     // 스택에 두 개 이상 남아있을 때까지 반복
//     while(st.size()>1)
//     {
//         // 좌항
//         int a= st.top();
//         st.pop();
        
//         // 우항
//         int b= st.top();
//         st.pop();
        
//         // 최대공약수
//         int r= 1;
        
//         // 최대공약수 구하기
//         for(int j=1;j<=min(a,b);j++)
//         {
//             if(a%j==0 && b%j==0)
//             {
//                 r=j;
//             }
//         }
        
//         // 두 수의 최소공배수를 스택에 넣어주기
//         st.push(r*(a/r)*(b/r));
//     }
    
//     // 스택에 마지막으로 남은 수 하나가 최종 최소공배수임
//     int answer = st.top();
//     st.pop();
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    
    else{
        return gcd(b, a%b);
    }
}

int solution(vector<int> arr) {
    
    
    sort(arr.begin(),arr.end()); // 오름차순 정렬
    int curGcd = 0; // 최대 공약수
    int answer = arr[0]; // 현재까지의 최소공배수
    for(int i=1;i<arr.size();i++){
        int max1 = max(answer,arr[i]);
        int min1 = min(answer,arr[i]);
        curGcd = gcd(max1,min1); // 현재 비교 수 간의 최대 공약수
        answer = answer*arr[i]/curGcd; // 현재 수와 다음 수의 최소공배수 갱신
    }

    
    
    return answer;
}
