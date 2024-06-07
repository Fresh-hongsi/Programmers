#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> arr;
    string temp = "";
    
    for(int i=0;i<s.length();i++){
        char cur = s[i];
        if(cur==' '){
            arr.push_back(stoi(temp));
            temp="";
            continue;
        }
        else{
            temp+=(cur);
        }
    }
    arr.push_back(stoi(temp));
    
    int min = *min_element(arr.begin(),arr.end());
    int max = *max_element(arr.begin(),arr.end());
    
    answer+=to_string(min);
    answer+=' ';
    answer+=to_string(max);
    
    return answer;
}
