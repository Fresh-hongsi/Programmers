#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <iostream>
using namespace std;

bool comp(pair<int,int>a , pair<int,int> b){
    
    if(a.second == b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    vector<pair<int,int>> r;
    
    for(int i=0;i<routes.size();i++){
        int in = routes[i][0];
        int out = routes[i][1];
        
        r.push_back(make_pair(in,out));
    }
    
    sort(r.begin(),r.end(),comp);
    
    // for(int i=0;i<r.size();i++){
    //     cout<<r[i].first<<' '<<r[i].second<<'\n';
    // }
    
    answer = 1;
    int cur = r[0].second;
    
    for(int i=1;i<r.size();i++){
        if(r[i].first<=cur){
            continue;
        }
        else{
            answer++;
            cur = r[i].second;
        }
    }
    return answer;
}

// -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 -0
// 	-------
// --------------------------  
//             -------------------------
// 				  -------------------------------------
// 									    ---------


// --------------------------  
//             -------------------------
// 				  -------------------------------------
// 									    ---------
