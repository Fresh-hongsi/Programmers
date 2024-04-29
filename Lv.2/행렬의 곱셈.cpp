#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    answer.resize(arr1.size()); // 3x4 4x5 행렬의 크기는 3x5이므로, answer행렬의 행만 일단 세팅해둠
    
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2[0].size();j++){
            int temp = 0;
            for(int k=0;k<arr1[i].size();k++){
                temp+=arr1[i][k]*arr2[k][j];
                
            }
            
            answer[i].push_back(temp);
        }
    }
    return answer;
}

// 3*2 2*4
    
// 0

// 1 4  3 3 1 1
// 3 2  3 3 2 3
// 4 1
