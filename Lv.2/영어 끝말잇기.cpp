// #include <string>
// #include <vector>
// #include <iostream>
// #include <map>
// using namespace std;

// vector<int> solution(int n, vector<string> words) {
//     vector<int> answer;
    
//     map<string,int> m; // 현재까지 끝말잇기에 사용된 단어들을 map에 기록하기
    
//     // 끝말잇기 게임 시작
//     for(int i=0;i<words.size();i++)
//     {
//         int l1 = words[i].length(); // 현재 발화자가 말한 단어의 길이
//         int l2=0; // 현재 바로 전 발화자가 말한 단어의 길이
//         if(i>=1)
//         {
//             l2= words[i-1].length();
//         }
        
//         if(l1==1) // 현재 발화자가 말한 단어 길이가 1인 경우 - 게임 종료
//         {
//             int a= (i+1)%n; // 현재 발화자가 누구인지 계산
//             int b= ((i)/n)+1; // 현재 발화자의 몇번째 턴에 게임 종료인지 계산
//             if(a==0) // 특수한 경우 예외처리
//             {
//                 a+=n;
//             }
//             answer.push_back(a);
//             answer.push_back(b);
//             break;
//         }
        
//         // 앞선 발화자의 마지막 알파벳과 현재 발화자의 첫 알파벳이 다른 경우 - 게임 종료
//         else if(i>=1 && (words[i-1][l2-1] != words[i][0])) 
//         {
//             int a= (i+1)%n; // 현재 발화자가 누구인지 계산
//             int b= ((i)/n)+1; // 현재 발화자의 몇번째 턴에 게임 종료인지 계산
//             if(a==0) // 특수한 경우 예외처리
//             {
//                 a+=n;
//             }
//             answer.push_back(a);
//             answer.push_back(b);
//             break;
            
//         }
        
//         // 현재 발화자가 말한 단어가 이미 누군가가 말했던 단어라면 - 게임 종료
//         else if(i>=1 && m.find(words[i])!=m.end())
//         {
//             int a= (i+1)%n; // 현재 발화자가 누구인지 계산
//             int b= ((i)/n)+1; // 현재 발화자의 몇번째 턴에 게임 종료인지 계산
//             if(a==0) // 특수한 경우 예외처리
//             {
//                 a+=n;
//             }
//             answer.push_back(a);
//             answer.push_back(b);
//             break;
//         }
        
//         // 매 턴이 끝날 때, map에 현재 말한 단어를 기록
//         m.insert({words[i],1});
//     }
    
//    // 만약 끝말잇기가 끝나지 않은 경우, (0,0)으로 세팅 
//    if(answer.empty())
//    {
//        answer.push_back(0);
//        answer.push_back(0);
//    }
//     // 그 외의 경우, 세팅된 값을 반환
//     return answer;
// }
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <set>
// using namespace std;

// vector<int> solution(int n, vector<string> words) {
    
//     bool flag = true;
//     vector<int> answer;
//     set<string> s;
//     s.insert(words[0]);
//     int who = 0; // 틀린 사람 번호
//     int num = 0; // 몇번째 턴에서 틀렸는지
//     for(int i=1;i<words.size();i++){
        
//         string front = words[i-1];
//         string cur = words[i];
        
//         // cur이 이미 나온 단어라면
//         if(s.find(cur)!=s.end()){
//             flag = false;
//             who = (i+1)%n;
//             if(who==0){
//                 who=n;
//             }
//             num = i/n+1;
//             break;
//         }
        
//         // cur의 첫번째 문자와 front의 마지막 문자가 다르다면
//         else if(front[front.length()-1]!=cur[0]){
           
//             flag = false;
//             who = (i+1)%n;
//             if(who==0){
//                 who=n;
//             }
//             num = i/n+1;
//             break;
//         }
        
//         // 그 외의 경우 set에 현재 cur 넣기
//         else{
//             s.insert(cur);
//         }
        
//     }
    
//     if(flag==true){
//         answer.push_back(0);
//         answer.push_back(0);
//     }
//     else{
//         answer.push_back(who);
//         answer.push_back(num);
//     }
//     return answer;
// }


#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> stringSet;
    
    for(int i=1;i<=words.size();i++){
        
        if(stringSet.size()==0){
            stringSet.insert(words[i-1]);
        }
        
        else{
            string cur = words[i-1];
            string front = words[i-2];
            
            if((stringSet.find(cur)!=stringSet.end()) || (front[front.length()-1]!=cur[0]) ){ // 이미 있는 단어거나 끝말잇기가 불가능한 단어일 경우
                
                //몇번째 사람이 몇번째 시도에 걸린 건지 구하기
                if(i%n==0){
                    answer.push_back(n);    
                }
                else{
                    answer.push_back(i%n);    
                }
                
                if(i/n==0){
                    answer.push_back(1);
                }
                else{
                    if(i%n==0){
                        answer.push_back((i/n));
                    }
                    else{
                        answer.push_back((i/n)+1);
                    }
                }
                
                break;
            }
            
            else{ // 끝말잇기가 가능한 정상적인 경우 -> 단어 추가
                stringSet.insert(cur);
            }
        }
    }
    
    // 아무도 안걸린 경우
    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    
    return answer;
}
