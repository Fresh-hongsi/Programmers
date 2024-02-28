#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> m;
    
    for(int i=0;i<s.length();i++){
        
        if(m.find(s[i])==m.end()){ // map에 없으면
            
            m.insert(make_pair(s[i],i));
            answer.push_back(-1);
            
        }
        
        else{ // map에 있으면
            
            answer.push_back(i-m[s[i]]);
            m[s[i]] = i;
                
            
        }
    }
    
    
    return answer;
}
