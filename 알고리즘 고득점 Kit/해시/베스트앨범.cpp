#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    
    // 음악 장르와 장르별 재생 수 합계를 저장할 map
    map<string,int> music;
    
    // 각 장르별로, 음악마다의 재생 수를 저장할 map, 삽입된 map의 first는 index, second는 재생 횟수
    map<string, map<int,int>> musicList;
    
    for(int i=0;i<genres.size();i++){
        string genre = genres[i];
        int play = plays[i];
        music[genre]+=play;
        musicList[genre][i]=plays[i];
    }
    
    //장르가 다없어질때까지 반복
    while(music.size()>0){
        
        // 가장 많이 재생된 장르 찾기
        string maxGenre="";
        int maxPlay=0;
        
        for(auto temp: music){
            if(maxPlay<temp.second){
                maxPlay = temp.second;
                maxGenre = temp.first;
            }
        }
        
        // 현재 장르에서 가장 많이 재생된 곡 두개 뽑기
        for(int i=0;i<2;i++){
            int val = 0;
            int idx = -1;
            
            for(auto cur: musicList[maxGenre]){
                if(val < cur.second){
                    val = cur.second;
                    idx = cur.first;
                }
            }
            
            // 만약 곡이 더 없다면, 플레이리스트에 추가 멈추기
            if(idx==-1){
                break;
            }
            
            // 선정된 곡을 플리에 추가
            answer.push_back(idx);
            // 그리고 musicList에서 지워주기
            musicList[maxGenre].erase(idx);
            
            
        }
        
        // 해당 장르 없애기
        music.erase(maxGenre);
        
        
    }
    return answer;
    
    
}
