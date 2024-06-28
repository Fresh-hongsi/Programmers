#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    int answer = 0;
    vector<string> cache; //LRU -> 가장 오랫동안 참조되지 않은 페이지를 교체
    
    if(cacheSize==0){ // 만약 캐시 사이즈가 0이라면, 모두 캐시 미스이므로, 각 실행시간은 5
        answer = cities.size()*5;
    }
    else{
        for(int i=0;i<cities.size();i++){ // 순차적으로 접근해봄
            string cur = cities[i];
            transform(cur.begin(),cur.end(),cur.begin(),::tolower); // 문자열을 소문자로 변환하는 로직
            
            auto it = find(cache.begin(),cache.end(),cur);
            if(it!=cache.end()){ // 캐시 히트인 경우
                cache.erase(it); // 해당 문자열 캐시 지우고
                cache.push_back(cur); // 캐시 가장 뒷부분에 넣어주기
                answer+=1; // cache hit 연산
            }
            
            else{ // 캐시 미스인 경우
                
                // 캐시가 꽉 찬 경우
                if(cache.size()>=cacheSize){
                    cache.erase(cache.begin()); // 가장 오래된 거 제거
                    cache.push_back(cur); // 캐시 가장 뒷부분에 넣어주기
                    answer+=5; // cache miss 연산
                }
                                
                // 캐시 여유 공간이 있을 경우
                else{
                    cache.push_back(cur); // 캐시 가장 뒷부분에 넣어주기
                    answer+=5; // cache miss 연산
                }
            }
            
        }
    }
    return answer;
}
