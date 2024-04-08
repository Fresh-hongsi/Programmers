#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(),lost.end()); // 오름차순 정렬
    sort(reserve.begin(),reserve.end()); // 오름차순 정렬
    
    set<int> lostStudentSet; // 잃어버린 사람이 체육복을 구헀는 지 현황을 관리하기 위한 set
    
    // 잃어버린 사람 등록
    for(int i=0;i<lost.size();i++){
        lostStudentSet.insert(lost[i]); 
    }    
    
    // 잃어버린 사람 중 여분 가져온 사람은 set에서 제거
    for(int i=0;i<reserve.size();i++){
        
        int cur = reserve[i];
        if(lostStudentSet.find(cur)!=lostStudentSet.end()){ // 자기 자신 거 잃어버렸는 지 확인
            lostStudentSet.erase(cur);
            reserve[i]=0; // 여분 가져온 것으로 해결 되었으므로 해당 사람은 0 표시
            
        }
    }
    
    
    // 잃어버린 사람 중 여분 없는 사람에 대해 체육복을 빌려줌
    for(int i=0;i<reserve.size();i++){
        
        int cur = reserve[i];
        if(cur!=0){ // 체육복 여분 있는 사람에 대해
            if(lostStudentSet.find(cur-1)!=lostStudentSet.end()){ // 앞 사람이 체육복 없으면 빌려줌
                lostStudentSet.erase(cur-1);
            }
            else if(lostStudentSet.find(cur+1)!=lostStudentSet.end()){ // 뒷 사람이 체육복 없으면 빌려줌
                lostStudentSet.erase(cur+1);
            }
        }
        
    }
    
    answer = n-lostStudentSet.size();
    return answer;
}





// 2 5 7 8
// 1 4 5 7
// // 무조건 앞에 있는 사람이 자기나 뒤에 있는 사람 
// 2 4
// 3 5

// 3 4 5
// 2 3 6
