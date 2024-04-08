#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string process1(string s){
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    return s;
}

string process2(string s){
    string temp="";
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') || s[i]=='-' || s[i] =='_' || s[i]=='.' ){
            temp+=s[i];
        } 
    
    }
    return temp;
    
}

string process3(string s){
    
    string temp="";
    temp+=(s[0]);
    for(int i=1;i<s.length();i++){
        if(s[i]=='.' && s[i-1]=='.'){
            continue;
        }
        else{
            temp+=s[i];
        }
    }
    
    return temp;
}

string process4(string s){
    string temp="";
    
    for(int i=0;i<s.length();i++){
        if(i==0 && s[i]=='.') continue;
        if(i==s.length()-1 && s[i]=='.') continue;
        temp+=s[i];
    }
    return temp;
}

string process5(string s){
    if(s.length()==0){
        s+="a";
    }
    
    return s;
}

string process6(string s){
    if(s.length()>=16){
        s=s.substr(0,15);
    }
    if(s[14]=='.'){
        s.erase(s.begin()+14);
    }
    
    return s;
}

string process7(string s){
    if(s.length()<=2){
        char x = s[s.length()-1];
        while(s.length()<3){
            s+=x;
        }
    }
    
    return s;
}

string solution(string new_id) {
    string answer = "";
    
    string afterProcess1 = process1(new_id);
    cout<<afterProcess1<<'\n';
    
    string afterProcess2 = process2(afterProcess1);
    cout<<afterProcess2<<'\n';
    
    string afterProcess3 = process3(afterProcess2);
    cout<<afterProcess3<<'\n';
    
    string afterProcess4 = process4(afterProcess3);
    cout<<afterProcess4<<'\n';
    
    string afterProcess5 = process5(afterProcess4);
    cout<<afterProcess5<<'\n';
    
    string afterProcess6 = process6(afterProcess5);
    cout<<afterProcess6<<'\n';
    
    string afterProcess7 = process7(afterProcess6);
    cout<<afterProcess7<<'\n';
    
    answer = afterProcess7;
    return answer;
}
