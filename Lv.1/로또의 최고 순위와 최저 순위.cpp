#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    
    set<int> this_week_num; // 이번주 추첨 번호
    // 추첨 번호를 set에 저장
    for(int i=0;i<win_nums.size();i++){
        this_week_num.insert(win_nums[i]);
    }
    
    int matchedNum = 0; // 이번 주 추첨 번호랑 내 번호랑 몇개 맞는 지 확인할 변수(확인 할 수 있는 번호 중에)
    int zeroCount = 0; // 내 번호 중 0의 개수
    for(int i = 0; i<lottos.size();i++){
        
        if(this_week_num.find(lottos[i])!=this_week_num.end()){
            matchedNum++;
        }
        
        if(lottos[i]==0){
            zeroCount++;
        }
    }
    
    int maxMatchedPoint = matchedNum+zeroCount; // 가장 많이 맞췄을 때 개수
    int minMatchedPoint = matchedNum; // 가장 적게 맞췄을 때 개수
    

    // 개수별 등수 계산
    
    // 최대 등수 계산
    if(7-maxMatchedPoint>=6 ){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-maxMatchedPoint);
    }
    
    // 최저 등수 계산
    if(7-minMatchedPoint>=6 ){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-minMatchedPoint);
    }
    
    
    return answer;
}

// 44 1 0  0 31 25
// 45 1 6 10 31 19
    
// 2 + 2 = 4 -> 3
// 2 + 0 = 2 -> 5
    

// 0 + 6 = 6 -> 1
// 0 + 0 = 0 -> 6
    
// 6 + 0 = 6 -> 1
// 6 + 0 = 6 -> 1   (1+6 = 7)
