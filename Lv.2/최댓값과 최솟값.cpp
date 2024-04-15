#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

string solution(string s) {
    
    vector<int> arr;
    string temp = "";
    
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            arr.push_back(stoi(temp));
            temp="";
        }
        
        else{
            temp+=s[i];
        }
    }
    arr.push_back(stoi(temp));
    
    int minimum = *min_element(arr.begin(),arr.end());
    int maximum = *max_element(arr.begin(),arr.end());
    
    string answer = "";
    answer+=to_string(minimum);
    answer+=" ";
    answer+=to_string(maximum);
    return answer;
}
