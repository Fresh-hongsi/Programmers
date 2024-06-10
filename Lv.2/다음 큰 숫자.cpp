// #include <string>
// #include <vector>

// using namespace std;

// int solution(int n) {
//     int answer = 0;
    
//     string cur="";
//     string next="";
//     int cur1Count=0; // 처음 들어온 n값에 대한 1의 개수
//     int next1Count=0; // 앞으로 계속 n값을 증가시켜보면서 1값을 count할 변수
//     int temp=n; // 처음엔 temp변수에 n을 세팅
    
//     // 처음 수 n에 대해서 1의 갯수 count하기
//     while(temp>0)
//     {
//         if(temp%2==0)
//         {
//             cur+='0';
//         }
//         else
//         {
//             cur+='1';
//             cur1Count++;
//         }
//         temp/=2;
//     }
    
//     // n값을 1씩 증가시켜보면서 해당 수에 1이 몇개 있는지 count하기
//     while(1)
//     {
//         n+=1;
//         temp=n;
//         next1Count=0;
        
//         while(temp>0)
//         {
//             if(temp%2==0)
//             {
//                 next+='0';
//             }
//             else
//             {
//                 next+='1';
//                 next1Count++;
//             }
//             temp/=2;
//         }
        
//         // 처음 들어온 수의 1개수와 1씩 증가시켜보면서 count한 1의 갯수가 같다면 while문 종료
//         if(cur1Count==next1Count)
//         {
//             answer=n;
//             break;
//         }
        
        
//     }
    
    
//     return answer;
// }

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <functional>
// using namespace std;

// int func(int n){
    
//     int count = 0;
//     while(n>0){
//         if(n%2==1){   
//             count++;
//         }
//         n/=2;        
//     }
    
//     return count;
// }

// int solution(int n) {
//     int answer = 0;
    
//     bool flag = false;
    
//     int nCount = 0;
//     int mCount = 0;
    
//     nCount = func(n);
//     while(1){
//         n++;
//         mCount = func(n);
//         if(nCount==mCount){
//             flag = true;
//             break;
//         }
//     }
//     answer = n;
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int check(int k){ // 2진수로 변환 후, 1의 개수가 몇개인지 반환하는 함수
    
    int numOfOne = 0;
    
    while(k!=0){
        if((k%2)==1){
            numOfOne++;
        }
        k/=2;
    }
    
    return numOfOne;
}

int solution(int n) {
    int answer = n;
    
    int numOfOneInN = check(n);
    
    while(1){
        answer++;
        
        int numOfOneInAnswer = check(answer);
        if(numOfOneInN==numOfOneInAnswer){
            break;
        }
    }
    return answer;
}
