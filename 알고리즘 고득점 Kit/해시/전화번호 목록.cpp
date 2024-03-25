#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(),phone_book.end());
    bool answer = true;
    string prefix = phone_book[0];
    int prefixLength = prefix.length();
    

    for(int i=0;i<phone_book.size()-1;i++){
        
            
        int count = 0;
        for(int k=0;k<phone_book[i].size();k++){
                
            if(phone_book[i][k]==phone_book[i+1][k]){ 
                    count++;
            }
        }
        
        // flag 가 true인 게 있다면 바로 false처리
        if(count == phone_book[i].size()){
            return false;
        }
        
        
        
        
    }
    
    return answer;
}
