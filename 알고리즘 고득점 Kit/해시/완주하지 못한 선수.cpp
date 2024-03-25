#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    
    for(int i=0;i<participant.size();i++){
        string temp = participant[i];
        if(m.count(temp)==0){
            m.insert(make_pair(temp,1));
        }
        
        else{
            m[temp]++;
        }
    }
    
    for(int i=0;i<completion.size();i++){
        string temp = completion[i];
        
        m[temp]--;
    }
    
    for(auto iter: m){
        if(iter.second==1){
            answer=iter.first;
            break;
        }
    }
    
    
    
    
    
    
    return answer;
}
