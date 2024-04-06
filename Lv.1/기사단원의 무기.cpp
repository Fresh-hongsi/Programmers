#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int countPoint(int num){ // 빠른 약수 계산 모듈 : https://www.geeksforgeeks.org/count-divisors-n-on13/     
    int ans = 0;
    for(int i=1;i<=sqrt(num);i++){
        if(num%i==0){
            
            if(num/i==i){
                ans++;
            }
            else{
                ans+=2;
            }
        }
    }
    
    return ans;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> arr;
    
    for(int i=1;i<=number;i++){
        int point = countPoint(i);
        if(point>limit){
            point = power;
        }
        
        arr.push_back(point);
    }
    
    for(int i=0;i<arr.size();i++){
        answer +=arr[i];

  
    }
    return answer;
}
