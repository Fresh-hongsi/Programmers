#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int n = 0; // sort_by에 입력된 것이 무엇인가에 따라 정렬 기준을 변경하여 수행

bool compare(vector<int> a, vector<int> b){
    
    return a[n] < b[n];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for(int i=0;i<data.size();i++){
        
        int code = data[i][0];
        int date = data[i][1];
        int maximum = data[i][2];
        int remain = data[i][3];
        
        if(sort_by=="code"){
            n=0;
        }else if(sort_by=="date"){
            n=1;
        }else if(sort_by=="maximum"){
            n=2;
        }else if(sort_by=="remain"){
            n=3;
        }
        
        if(ext=="code" && val_ext>code){
            answer.push_back(data[i]);
            
            
        }else if(ext=="date" && val_ext>date){
            answer.push_back(data[i]);
            
            
        }else if(ext=="maximum" && val_ext>maximum){
            answer.push_back(data[i]);
            
            
        }else if(ext=="remain" && val_ext>remain){
            answer.push_back(data[i]);
            
        }else{
            continue;
        }
    }
    
    sort(answer.begin(),answer.end(),compare);
    return answer;
}
