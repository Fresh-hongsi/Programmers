#include <string>
#include <vector>
#include <set> // 중복 없이 담을 수 있음
#include <algorithm>
#include <math.h>

using namespace std;

// num이 소수인지 아닌지 판별하는 하수
bool checkPrime(int num){
    
    
    if(num<2){
        return false;
    }
    
    bool flag = true; // 소수임을 가정하고 시작
    
    
    for(int i=2;i<=sqrt(num);i++){ // 최적화 위해 sqrt(num)까지만 반복
        if(num%i==0){
            return false;
        }
    }
    
    return flag;
}

int solution(string numbers) {
    
    set<int> primeSet; // 문자열 내의 문자를 조합해서 만들 수 있는 수 중에서 소수만 저장할 집합
    vector<int> numArr; // 순열 돌릴 vector
    
    for(int i = 0;i<numbers.length();i++){
        numArr.push_back(numbers[i]-'0');
    }
    
    // next_permutation쓰려면 정렬되어있어야함
    sort(numArr.begin(),numArr.end());
    
    do{
        string temp="";
        for(int i=0;i<numArr.size();i++){
            temp+=to_string(numArr[i]); // 해당 순열에서 문자 하나씩 뒤에 추가하면서 소수 판별 시도
            if(checkPrime(stoi(temp))){ // 해당 숫자가 소수라면 집합에 추가
                primeSet.insert(stoi(temp));
            }
            
        }
        
    }while(next_permutation(numArr.begin(),numArr.end()));
    
    return primeSet.size();

}
