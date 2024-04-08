#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int curL = 10; // 왼손 시작점 : *
    int curR = 12; // 오른손 시작점 : #
    
    for(int i=0;i<numbers.size();i++){
        
        int cur = numbers[i]; // 현재 타겟 키
        if(cur==1 || cur==4 || cur==7){ 
            answer+='L';
            curL=cur;
        }
        else if(cur==3 || cur==6 || cur==9){
            answer+='R';
            curR=cur;
        }
        else{ // 2,5,8,0일 경우
            
            if(cur==0){
                cur=11;
            }
            int lengthLeft = abs(curL-cur)/3+abs(curL-cur)%3; // 현재 왼손 위치와 타겟과의 거리
            int lengthRight = abs(curR-cur)/3+abs(curR-cur)%3; // 현재 오른손 위치와 타겟과의 거리
            if(lengthLeft<lengthRight){ //왼손과 가까울 경우
                answer+='L';
                curL=cur;
            }
            else if(lengthLeft>lengthRight){ //오른손과 가까울 경우
                answer+='R';
                curR=cur;
            }
            else{ // 같을 경우 손잡이로 결정
                if(hand=="right"){
                    answer+='R';
                    curR=cur;
                }else{
                    answer+='L';
                    curL=cur;
                }
            }
        }
    }
    return answer;
}

