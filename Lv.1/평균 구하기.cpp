#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int i: arr)
    {
        answer+=i;
    }
    
    answer= answer/(double)arr.size();
    return answer;
}
