#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    
    string p1="12345";
    string p2="21232425";
    string p3="3311224455";
    
    while(p1.length()<10001){
        p1+=p1;
        p2+=p2;
        p3+=p3;
    }
    
    string s;
    for(int i=0;i<answers.size();i++){
        s+=to_string(answers[i]);
    }
    
    int count1=0;
    int count2=0;
    int count3=0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]==p1[i]){
            count1++;
        }
        if(s[i]==p2[i]){
            count2++;
        }
        if(s[i]==p3[i]){
            count3++;
        }
    }
    
    vector<int> temp;
    temp.push_back(count1);
    temp.push_back(count2);
    temp.push_back(count3);
    
    sort(temp.begin(),temp.end(),greater<>());
    
    int result = temp[0];
    vector<int> answer;
    if(count1==result){
        answer.push_back(1);
    }
    
    if(count2==result){
        answer.push_back(2);
    }
    
    if(count3==result){
        answer.push_back(3);
    }
 
    return answer;
}
