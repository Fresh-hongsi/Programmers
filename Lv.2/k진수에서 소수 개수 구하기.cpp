#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

// convNum진수로 변환
string invert(int val, int convNum){
    string answer = "";
    char numSet[10]={'0','1','2','3','4','5','6','7','8','9'};
    
    while(val>0){
        answer+=numSet[val%convNum];
        val/=convNum;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

// 소수인지 판별
bool isPrime(long k){
    
    if(k==1){
        return false;
    }
    
    for(long i=2;i*i<=k;i++){
        if(k%i==0){
            return false;
        }
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    vector<long> arr;
    string s = invert(n,k);
    // cout<<s;
    
    // 0 기준으로 split
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' && temp.length()>0){
            arr.push_back(stol(temp));
            temp="";
        }
        else if(s[i]!='0'){
            temp+=s[i];
        }
    }
    if(temp.length()>0){
        arr.push_back(stol(temp));
    }
    
    // split한 각 요소가 소수인지 판별
    for(long p: arr){
        //cout<<p<<' ';
        if(isPrime(p)){
            answer++;
        }
    }
    return answer;
}
