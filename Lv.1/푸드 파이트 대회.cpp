#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    
    string answer = "";
    string first = "";
    for(int i=1;i<food.size();i++){
        
        int temp = food[i]/2;
        for(int j=0;j<temp;j++){
            first+=to_string(i);
        }
    }
    
    answer=first;
    answer+="0";
    reverse(first.begin(),first.end());
    answer+=first;
    
    return answer;
}
