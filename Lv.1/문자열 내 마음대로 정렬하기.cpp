#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int k = 0;

bool comp (string a, string b){
    if(a[k] != b[k]){
        return a[k]<b[k];
    }
    
    else{
        return a<b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    k = n;
    
    sort(strings.begin(),strings.end(),comp);
    
    
    return strings;
}
