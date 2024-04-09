#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <functional>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lr = 51; // 좌측 행값 
    int lc = 51; // 좌측 열값
    int rr = 0; // 우측 행값
    int rc = 0; // 우측 열값
    
    
    for(int i=0;i<wallpaper.size();i++){ //행
        for(int j=0;j<wallpaper[i].length();j++){//열
            
            if(wallpaper[i][j]=='#'){
                if(lr>=i){
                    lr=i;
                }
                if(lc>=j){
                    lc=j;
                }
                if(rr<=i){
                    rr=i;
                }
                if(rc<=j){
                    rc=j;
                }
                
            }
            
        }
    }
    answer.push_back(lr);
    answer.push_back(lc);
    answer.push_back(rr+1);
    answer.push_back(rc+1);
    
    
    return answer;
}

