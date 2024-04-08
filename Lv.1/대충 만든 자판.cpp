#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> m;
    
    // 모든 자판을 검토하며 각 문자를 작성하기 위한 최소 입력 횟수를 count해서 map에 저장
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].length();j++){
            char cur = keymap[i][j];
            if(m.find(cur)!=m.end()){ // 해당 문자가 map에 이미 있는 경우
                // 최솟값이면 change
                if(m[cur]>j+1){
                    m[cur]=j+1;
                }
            }
            else{ // 해당 문자가 map에 없는 겨우
                m[cur]=j+1;
                
            }
        }
    }
    
    // 모든 target문자열을 표현하기 위한 최소 입력횟수를 count하기
    for(int i=0;i<targets.size();i++){
        int count = 0;
        for(int j=0;j<targets[i].length();j++){
            char curTarget = targets[i][j];
            if(m.find(curTarget)==m.end()){ // 없는 문자일 경우 -1 
                count=-1;
                break;
            }
            else{
                count += m[curTarget]; // 있는 문자일 경우 해당 문자에 대한 최소 입력 횟수 값을 더해주기
        
            }
        }
        answer.push_back(count);
    }
    return answer;
}
