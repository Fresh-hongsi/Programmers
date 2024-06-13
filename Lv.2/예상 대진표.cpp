// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(int n, int a, int b)
// {

//     int round = 1;
//     int answer = 0;
//     int t1 = min(a-1,b-1);
//     int t2 = max(a-1,b-1);

    
//     while(1)
//     {
       
//         if(t1%2==0 && t2%2==1 && t1+1==t2){
//             answer = round;
//             break;
//         }
        
//         else{
//             t1/=2;
//             t2/=2;
//             round++;
//         }
//     }


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    int minimum = min(a,b);
    int maximum = max(a,b);
    //cout<<minimum<<' '<<maximum<<'\n';

    while(1){
        if(minimum+1==maximum){
            
            if((minimum%2==1) && (maximum%2==0)){
                break;
            }
        }
        
        answer++;
        if(minimum%2==0){
            minimum/=2;
        }else{
            minimum/=2;
            minimum+=1;
        }
            
        if(maximum%2==0){
            maximum/=2;
                
        }else{
            maximum/=2;
            maximum+=1;
        }
        
    }
    return answer;
}

// 1 2 3 4 5 6 7 8 
// 1 4 5 8
// 4 5
    

    

    
//     return answer;
// }
