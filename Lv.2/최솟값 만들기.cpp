#include <iostream>
#include<vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    for(int i=0;i<A.size();i++){
        int temp = 0;
        temp=A[i]*B[i];
        answer+=temp;
    }
    return answer;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional>
// using namespace std;

// int solution(vector<int> A, vector<int> B)
// {
//     int answer = 0;

//     sort(A.begin(),A.end());
//     sort(B.begin(),B.end(),greater<int>());
    
//     for(int i=0;i<A.size();i++){
//         answer+=A[i]*B[i];
//     }
    
//     return answer;
// }
