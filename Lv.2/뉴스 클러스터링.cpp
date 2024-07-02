#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    map<string,int> str1Map; // str1을 두 글자씩 끊어서 다중집합의 원소로 구분한 후, <문자열,개수>로 저장하는 map
    map<string,int> str2Map; // str2을 두 글자씩 끊어서 다중집합의 원소로 구분한 후, <문자열,개수>로 저장하는 map
    int numOfIntersection=0; // 두 다중집합의 교집합 개수
    int totalElement = 0; // 두 다중집합의 모든 원소 개수 합 -> 즉 n(A)+n(B)  ---> 추후 n(AUB)는 totalElement-numOfIntersection으로 구할 것임
    
    // str1을 두글자씩 끊어서 다중집합 원소로 구분한 후, map에 저장. 이때, 알파벳이 아닌 경우는 집합 원소에 배제
    for(int i=0;i<str1.length()-1;i++){
        string temp = "";
        if((str1[i]>='a' && str1[i]<='z') || (str1[i]>='A' && str1[i]<='Z')){
            temp+=str1[i];
        }
        else{
            continue;
        }
        
        if((str1[i+1]>='a' && str1[i+1]<='z') || (str1[i+1]>='A' && str1[i+1]<='Z'))
        {
            temp+=str1[i+1];
        }
        else{
            continue;
        }
        
        transform(temp.begin(),temp.end(),temp.begin(),::tolower); // 문자열을 무조건 소문자로 변환
        str1Map[temp]++; // map에 저장
        totalElement++; // 전체 개수 카운터 1증가
        
    }
    
     // str2을 두글자씩 끊어서 다중집합 원소로 구분한 후, map에 저장. 이때, 알파벳이 아닌 경우는 집합 원소에 배제
    for(int i=0;i<str2.length()-1;i++){
        string temp = "";
        if((str2[i]>='a' && str2[i]<='z') || (str2[i]>='A' && str2[i]<='Z')){
            temp+=str2[i];
        }
        else{
            continue;
        }
        
        if((str2[i+1]>='a' && str2[i+1]<='z') || (str2[i+1]>='A' && str2[i+1]<='Z'))
        {
            temp+=str2[i+1];
        }
        else{
            continue;
        }
        
        transform(temp.begin(),temp.end(),temp.begin(),::tolower); // 문자열을 무조건 소문자로 변환
        str2Map[temp]++; // map에 저장
        totalElement++; // 전체 개수 카운터 1증가
    } 
        

    // 두 집합의 교집합 개수 구하기 - 만약 str1의 집합 크기가 더 큰 경우
    if(str1Map.size()>str2Map.size()){
        for(auto k: str1Map){
            int num = 0;
            string key = k.first;
            if(str2Map.find(key)!=str2Map.end()){ // 있다면
                num = min(str1Map[key],str2Map[key]);    
            }
            numOfIntersection+=num;      
        }
    }
    else{ // 두 집합의 교집합 개수 구하기 - 만약 str2의 집합 크기가 더 큰 경우
        
        for(auto k: str2Map){
            int num = 0;
            string key = k.first;
            if(str1Map.find(key)!=str1Map.end()){ // 있다면
                num = min(str1Map[key],str2Map[key]);    
            }
            numOfIntersection+=num;      
        }
        
    }
    
    int numOfUnion = totalElement-numOfIntersection; // 합집합 개수 계산
    
    //cout<<numOfIntersection<<' '<<numOfUnion-numOfIntersection<<'\n';
    
    if(numOfIntersection==0 && numOfUnion==0){ // 자카드 유사도 계산을 할 수 없는 경우
        answer=65536;
    }
    else{ // 자카드 유사도를 계산할 수 있는 경우
        double result = ((double)numOfIntersection / (double)(numOfUnion))*65536;
        answer=(int)result;
    }
    
    return answer;
}

// 1:2   1:1
// 2:2   2:2 
// 3:1   4:1
//       5:1
