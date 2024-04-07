#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <functional>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 에라토스테네스의 채 이용
    bool isPrime[1000001];
    for(int i=0;i<1000001;i++){
        isPrime[i]=true;
    }
    
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=sqrt(1000001);i++){
        if(isPrime[i]==true){
            for(int j=2*i;j<1000001;j+=i){
                isPrime[j]=false;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(isPrime[i]==true){
            answer++;
        }
    }
    return answer;
}
