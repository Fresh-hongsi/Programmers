#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int card1Idx=0;
    int card2Idx=0;
    int goalIdx=0;
    bool flag = false;
    while(1){
        
        if(goalIdx == goal.size()){
            flag = true;
            break;
        
        }
            
        if(cards1[card1Idx]==goal[goalIdx]){
            card1Idx++;
            goalIdx++;
        }
        else if(cards2[card2Idx]==goal[goalIdx]){
            card2Idx++;
            goalIdx++;
        }
        else{
            break;
        }
            
        
    }
    
    if(flag==true){
        answer="Yes";
    }
    else{
        answer="No";
    }
    return answer;
}
