#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <functional>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    
    for(int i=0;i<operations.size();i++){
        
        string s = operations[i];
        stringstream ss(s);
        
        string op;
        string num;
        ss>>op>>num;
        int n = stoi(num);
        
        if(op=="I"){
            v.push_back(n);
        }
        
        else if(op=="D"){
            if(n==-1){
                if(v.size()>0){
                    //cout<<"min"<<*min_element(v.begin(),v.end())<<'\n';
                    auto it = min_element(v.begin(),v.end());
                    v.erase(it);
                    
                }
            }
            
            if(n==1){
                if(v.size()>0){
                    //cout<<"max"<<*max_element(v.begin(),v.end())<<'\n';
                    auto it = max_element(v.begin(),v.end());
                    v.erase(it);
                    
                }
            }
        }
    }
    
    for(auto k:v){
        cout<<k<<' ';
    }
    
    if(v.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*max_element(v.begin(),v.end()));
        answer.push_back(*min_element(v.begin(),v.end()));
    }
    return answer;
}
