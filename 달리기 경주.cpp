#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{

    map<int,string> m1; //순위, 이름
    map<string, int> m2; //이름, 순위

    for(int i=0;i<players.size();i++) //두개의 map에 순위, 이름 저장
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }

    for(int i=0;i<callings.size();i++)
    {
        string curName=callings[i]; //현재 사람 이름
        int curRank=m2[curName]; //현재 사람 순위

        string frontName=m1[curRank-1]; //앞선 사람 이름
        int frontRank=m2[frontName]; //앞선 사람 순위

        m1[frontRank]=curName; //앞선 사람 이름= 현재 사람 이름
        m2[frontName]=curRank;

        m1[curRank]=frontName; //현재 사람 이름= 앞선 사람 이름
        m2[curName]=frontRank;
    }


    vector<string>answer;
    for(int i=0;i<m1.size();i++)
    {
        answer.push_back(m1[i]);
    }

    return answer;
}
