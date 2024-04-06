#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> m;
    
    // map에 추가
    for(int i=0;i<name.size();i++){
        
        m[name[i]]=yearning[i];
        
    }
    
    // 각 사진별 점수 계산
    for(int i=0;i<photo.size();i++){
        int temp = 0;
        for(int j=0;j<photo[i].size();j++){
            if(m.find(photo[i][j])!=m.end()){
                temp+=m[photo[i][j]];
            }
            else{
                continue;
            }
        }
        answer.push_back(temp);
    }
    return answer;
}
