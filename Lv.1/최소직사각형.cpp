
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int>garo;
    vector<int>sero;
    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i][1]>sizes[i][0]) //세로가 더 긴 경우 가로 세로 값을 바꿔서 garo, sero에 넣어줌
        {
            garo.push_back(sizes[i][1]);  
            sero.push_back(sizes[i][0]);
        }
        else //가로가 더 긴 경우 그대로 garo sero에 넣어줌
        {
            garo.push_back(sizes[i][0]);    
            sero.push_back(sizes[i][1]);    
        }


    }

    sort(garo.begin(),garo.end(),greater<>());
    sort(sero.begin(),sero.end(),greater<>());
    answer=garo[0]*sero[0];
    return answer;
}
