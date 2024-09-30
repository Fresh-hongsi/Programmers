// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// using namespace std;

// string solution(string s) {
//     string answer = "";
    
//     answer+=toupper(s[0]);
    
//     for(int i=1;i<s.length();i++){
//         s[i-1]==' ' ? answer+=toupper(s[i]) : answer+=tolower(s[i]);
//     }
        
        
    
//     return answer;
// }


// // #include <string>
// // #include <vector>
// // #include <iostream>
// // #include <algorithm>
// // #include <functional>

// // using namespace std;

// // string solution(string s) {
// //     string answer = "";
    
// //     for(int i=0;i<s.length();i++){
// //         if(i==0){
// //             s[i]=toupper(s[i]);
// //         }
        
// //         else if(i>=1 && s[i-1]==' '){
// //             s[i]=toupper(s[i]);
// //         }
        
// //         else{
// //             s[i]=tolower(s[i]);
// //         }
// //     }
// //     answer=s;
// //     return answer;
    
// // }

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=0;i<s.length();i++){
        if(i==0){ // 첫번째 인덱스일 경우
            if(s[i]>='0' && s[i]<='9'){ // 숫자일 경우
                answer+=s[i]; // 그대로
            }
            else{ // 숫자가 아닐 경우
                answer+=toupper(s[i]);
            }
        }
        
        else{ // 두번째 이후 인덱스일 경우
            if(s[i]==' '){ // 공백이라면 그냥 추기
                answer+=s[i];
            }
            
            else{
                if(s[i-1]==' '){
                    if(s[i]==' '){
                       answer+=s[i]; 
                    }
                    else if(s[i]>='0' && s[i]<='9'){
                        answer+=s[i];
                    }
                    else{
                        answer+=toupper(s[i]);
                    }
                }
                else{
                    answer+=tolower(s[i]);
                }
            }
        }
    }
    return answer;
}
