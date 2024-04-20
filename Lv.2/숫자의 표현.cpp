// #include <string>
// #include <vector>

// using namespace std;

// int solution(int n) {
//     int answer = 0;
    
//     for(int i=1;i<=n;i++) // 1부터 차례대로 기준점 숫자 넣어보기
//     {
//         bool flag=true; //while문 실행 조건
//         int temp=i; // 기준점 숫자를 temo변수에 별도로 세팅
//         int sum=temp; // 각 for문 실행 때마다 sum의 시작값은 i값으로 세팅
        
//         while(flag)
//         {
//             if(sum==n) // 만족할 경우
//             {
//                 flag=false;
//                 answer++;
//                 break;
//             }
            
//             if(sum<n) // n보다 sum이 작을 경우엔 더 더해봐야함
//             {
//                 temp+=1;
//                 sum+=temp;
    
//             }
//             if(sum>n) // n보다 sum이 클 경우엔 더 while문을 돌 필요가 x
//             {
//                 break;
//             }
                    
//         }
//     }
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

// 투포인터 사용해보기
int solution(int n) {
    int answer = 1; // start가 n일 때의 경우 1개 값을 미리 카운트
    int start = 1; // 시작 포인터
    int end = 1; // 끝 포인터
    int sum = 1; // 현재 sum값
    while(start!=n){ // 시작 포인터가 n에 도달하기 전까지 반복
        
        if(sum==n){ // 만약 sum이 n이라면, 시작 포인터를 1증가시키고, sum값 업데이트
            sum-=start;
            start++;
            answer++;           
        }
        
        else if(sum<n){ // 만약 sum이 n보다 작다면, 끝 포인터를 1 증가시키고, sum값 업데이트
            end++;
            sum+=end;            
        }
        
        else{ // 만약 sum이 n보다 크다면, 시작 포인터를 1 증가시키고, sum값 업데이트 
            sum-=start;
            start++; 
            
        }
        
    }
    
    return answer;
    
    
}
