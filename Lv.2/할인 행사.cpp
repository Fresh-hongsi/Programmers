// #include <string>
// #include <vector>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// using namespace std;
// // 투 포인터 느낌으로 풀이

// map<string,int> wishList; // 정현이가 갖고 싶은 아이템과 그 개수 품목 map
// map<string,int> curDiscount; // 현재 기준으로 10일동안의 할인 아이템과 각 아이템의 할인일 수 현황

// // curDiscount에 적혀있는 할인품목 현황과 정현이의 위시리스트를 비교..  만일 정현이가 사고 싶은 것을 다 못사는 경우 false반환
// bool checkValid(){
    
//     bool flag = true;
    
//     for(auto wish : wishList){
//         string wishItem = wish.first;
//         int wishNum = wish.second;
        
//         if(curDiscount[wishItem]<wishNum){
//             flag = false;
//             break;
//         }
        
//     }
//     return flag;
// }

// int solution(vector<string> want, vector<int> number, vector<string> discount) {
//     int answer = 0;

//     string curFront = discount[0]; // 회원 등록 시점에 할인하는 아이템
    
//     // wishList 세팅
//     for(int i=0;i<want.size();i++){
//         wishList[want[i]]=number[i];
//     }
    
//     // 할인현황 품목 세팅
//     for(int i=0;i<10;i++){
//         curDiscount[discount[i]]++;
//     }

//     // 첫날의 경우는 직접 조사해봄
//     bool flag = checkValid();
//     if(flag == true){
//         answer++;
//     }
    
//     // 둘째날부터, 가능한 경우 모두 조사
//     for(int i=1;i<=discount.size()-10;i++){
//         curDiscount[curFront]--;
//         curFront = discount[i];
//         curDiscount[discount[i+9]]++;
//         bool flag = checkValid();
//         if(flag == true){
//             answer++;
//         }
//     }
//     return answer;
// }

// // 바나나:3
// // 사과: 2
// // 쌀: 2
// // 돼지고기: 2
// // 냄비: 1

// //  1    2   3    4    5   6    7       8       9    10  11   12    13   14
// // 치킨 사과 사과 바나나 쌀 사과 돼지고기 바나나 돼지고기 쌀 냄비 바나나 사과 바나나


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string,int> wishMap;
    
    // 정현이가 살 물건과 양을 wishMap으로 관리
    for(int i=0;i<want.size();i++){
        string key = want[i];
        int val = number[i];
        
        wishMap[key]=val;
    }
    
    // 0번째날부터 순차적으로 접근하며 10일동안 할인하는 품목을 discountMap으로 관리
    for(int i=0;i<=discount.size()-10;i++){
        map<string,int> discountMap;
        for(int j=0;j<10;j++){
            discountMap[discount[i+j]]++;
        }
        
        bool flag = true;
        for(auto k: wishMap){
            if(discountMap.find(k.first)!=discountMap.end())//wish품목이 discountMap에 하나라도 있다면
            {
                if(k.second<=discountMap[k.first]){//사려고 하는 양보다 discountMap에 더 많이 있다면 true 유지
                    flag=true;
                }
                else{ //사려고 하는 양보다 discountMap의 양이 더 적다면 불가함
                    flag=false;
                    break;
                }
            }   
            else{ //wish품목이 discountMap에 없다면 불가함
                flag=false;
                break;
            }
        }
        
        if(flag==true){
            answer++;
        }
        
    }
    
    
    return answer;
}
