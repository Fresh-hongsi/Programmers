#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int zCount = 0;
int convNum = 0;

string eraseZero(string s){
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            zCount++;
        }
        else{
            temp+=s[i];
        }
    }
    return temp;
}

string convTwo(int c){
    string temp = "";
    convNum++;
    while(c!=0){
        int t = c%2;
        c/=2;
        temp+=to_string(t);
    }
    
    reverse(temp.begin(),temp.end());
    return temp;
    
}
vector<int> solution(string s) {
    vector<int> answer;

    while(s!="1"){
        // 0을 제거한 문자열 반환
        s = eraseZero(s);
        
        // 0이 제거된 문자열의 길이에 대응하는 수를 이진수로 변환한 문자열 구하기
        int cur = s.length();
        string conv = convTwo(cur);
        // 그 문자열을 s로 다시 초기화 
        
        s = conv;
    }
    
    
    answer.push_back(convNum);
    answer.push_back(zCount);
    return answer;
}



// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// #include <map>
// #include <iostream>
// using namespace std;

// int a = 0;
// int b = 0;
// string conversion(string s){
    
//     string temp = "";
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='1'){
//             temp+="1";
//         }
//         else{
//             b++;
//         }
//     }
    
//     int k = temp.length();
//     string result = "";
//     while(k!=0){
//         result+=to_string(k%2);
//         k/=2;
//     }
    
//     reverse(result.begin(),result.end());
//     return result;
// }

// vector<int> solution(string s) {
//     vector<int> answer;
    


//     while(1){
//          s = conversion(s);
//          a++;
//          if(s=="1"){
//              answer.push_back(a);
//              answer.push_back(b);
//              break;
//          }
//     }
    
//     return answer;
// }

