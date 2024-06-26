// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <functional>
// using namespace std;

// int solution(vector<int> citations) {
//     int curH = 0;
    
    
//     while(1){
//         int count = 0;
//         for(int i=0;i<citations.size();i++){
//             if(curH<=citations[i]){
//                 count++;
//             }
//         }
        
//         if(count>=curH){
//             curH++;
//         }
//         else{
//             break;
//         }
//     }
    
//     return curH-1;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = 1;
    
    while(1){
        int count = 0;
        for(int i=0;i<citations.size();i++){
            if(h<=citations[i]){
                count++;
            }
        }
        if(count<h){
            answer=h-1;
            break;
        }
        else{
            h++;
        }
    }
    
    return answer;
}
