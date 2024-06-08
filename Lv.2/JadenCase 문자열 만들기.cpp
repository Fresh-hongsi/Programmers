#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string s) {
    string answer = "";
    
    answer+=toupper(s[0]);
    
    for(int i=1;i<s.length();i++){
        s[i-1]==' ' ? answer+=toupper(s[i]) : answer+=tolower(s[i]);
    }
        
        
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <functional>

// using namespace std;

// string solution(string s) {
//     string answer = "";
    
//     for(int i=0;i<s.length();i++){
//         if(i==0){
//             s[i]=toupper(s[i]);
//         }
        
//         else if(i>=1 && s[i-1]==' '){
//             s[i]=toupper(s[i]);
//         }
        
//         else{
//             s[i]=tolower(s[i]);
//         }
//     }
//     answer=s;
//     return answer;
    
// }
