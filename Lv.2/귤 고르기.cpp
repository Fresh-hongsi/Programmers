// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// // map을 value로 정렬하고 싶을 때는, map을 vector로 옮긴 후 comp 통해 정렬 수행해야함
// bool comp(pair<int,int> a, pair<int,int> b){
    
//     return a.second > b.second; // value기준 내림차순
// }
// int solution(int k, vector<int> tangerine) {
    
//     int answer = 0;
//     map<int,int> m; // key: 귤 크기, value: 각 크기의 귤 개수
    
//     // 크기별 귤 개수를 map에 저장
//     for(int i=0;i<tangerine.size();i++){
//         m[tangerine[i]]++;
//     }  
    
//     // 정렬을 위해 map을 vector로 복사
//     // 중요!!! map의 key value 쌍은 pair와 호환이 된다.
//     vector<pair<int,int>> v(m.begin(),m.end());
    
//     // value 기준 오름차순 정렬 수행
//     sort(v.begin(),v.end(),comp);
    
//     int count = 0;
    
//     for(int i=0;i<v.size();i++){
        
//         if(count>=k)
//             break;
        
//         count+=v[i].second;
//         answer++;
//     }
    

//     return answer;
// }


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0, sum = 0;
    map<int, int> ma;

    for(int i = 0; i < tangerine.size(); i++){
        ma[tangerine[i]]++;
    }

    vector<pair<int,int>> vec(ma.begin(), ma.end());
    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < vec.size(); i++){
        if(sum >= k)
            break;
        sum += vec[i].second;
        answer++;
    }

    return answer;
}


// 1: 1
//     2: 2
//         3: 2
//             4: 1
//                 5:2
                    
// 1:1
// 2:2
// 3:2
// 4:1
// 5:2
