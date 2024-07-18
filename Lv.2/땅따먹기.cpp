#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            if(j==0){
                land[i][j] = max(max(land[i-1][1],land[i-1][2]),land[i-1][3])+land[i][j];
            }
            
            else if(j==1){
                land[i][j] = max(max(land[i-1][0],land[i-1][2]),land[i-1][3])+land[i][j];
            }
            
            else if(j==2){
                land[i][j] = max(max(land[i-1][0],land[i-1][1]),land[i-1][3])+land[i][j];
            }
            
            else if(j==3){
                land[i][j] = max(max(land[i-1][0],land[i-1][1]),land[i-1][2])+land[i][j];
            }
        }
    }
    
    answer = *max_element(land[land.size()-1].begin(),land[land.size()-1].end());

    return answer;
}

