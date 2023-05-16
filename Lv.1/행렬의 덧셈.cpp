#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0;i<arr1.size();i++)
    {
        vector<int> temp; //anwer의 각 행에 들어갈 임시 1차원 벡터
        for(int j=0;j<arr1[0].size();j++) //
        {
            temp.push_back(arr1[i][j]+arr2[i][j]); //temp에 값 계산해서 넣어줌
        }
        answer.push_back(temp); //완성된 1차원 vector temp를 answer에 차례로 넣어줌
    }
    return answer;
}
