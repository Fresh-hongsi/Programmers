#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    set<pair<pair<int,int>,pair<int,int>>> s;
    
    int curX=0;
    int curY=0;
    
    for(int i=0;i<dirs.length();i++){
        int nextX=0;
        int nextY=0;
        if(dirs[i]=='U'){
            nextX=curX;
            nextY=curY+1;
        }
        
        if(dirs[i]=='L'){
            nextX=curX-1;
            nextY=curY;
        }
        
        if(dirs[i]=='R'){
            nextX=curX+1;
            nextY=curY;
        }
        
        if(dirs[i]=='D'){
            nextX=curX;
            nextY=curY-1;
        }
        
        if(nextX>=-5 && nextX<=5 && nextY>=-5 && nextY<=5){ // 범위 안에 있다면
            
            if(s.find(make_pair(make_pair(curX,curY),make_pair(nextX,nextY)))!=s.end()){ // 만약 이미 사용한 경로라면
                curX=nextX;
                curY=nextY;
                continue;
                
            }
            else{ // 만약 아직 사용하지 않은 경로라면
                //cout<<curX<<' '<<curY<<' '<<nextX<<' '<<nextY<<'\n';
                answer++; // 카운트
                s.insert(make_pair(make_pair(curX,curY),make_pair(nextX,nextY))); // 순방향 경로를 set에 추가
                s.insert(make_pair(make_pair(nextX,nextY),make_pair(curX,curY))); // 역방향 경로를 set에 추가
                curX=nextX;
                curY=nextY;

            }
            

            
            
        }
    }
    return answer;
}
