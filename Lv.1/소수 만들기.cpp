#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;



int solution(vector<int> nums) {
    int answer = 0;

    sort(nums.begin(), nums.end()); // 내림차순 정렬
    
    // 에라토스테네스의 채 이용
    bool prime[3000];
    for(int i=0;i<3000;i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<=sqrt(3000);i++){
        if(prime[i]==true){
            for(int j=2*i;j<3000;j+=i){
                prime[j]=false;
            }
        }
    }
    
    // 각 조합을 순회하며 소수인지 판별
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                int temp=nums[i]+nums[j]+nums[k];
                
                bool flag = prime[temp];
                if(flag==true){
                    answer++;
                }
            }
        }
    }
   
    return answer;
}
