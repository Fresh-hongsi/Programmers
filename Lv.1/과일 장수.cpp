#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(),score.end(),greater<int>()); // 내림차순 정렬
    for(int i=m-1;i<score.size();i+=m){
        answer+=score[i]*m;
    }

    return answer;
}
