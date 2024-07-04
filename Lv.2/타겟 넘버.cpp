#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt = 0;
vector<int> arr;

void dfs(int cur, int length, int goal){
    
    if(length==arr.size()){
        
        if(cur==goal){
            cnt++;
        }
        return;
    }
    

    dfs(cur+arr[length],length+1, goal);
    dfs(cur-arr[length],length+1, goal);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    
    for(int i=0;i<numbers.size();i++){
        arr.push_back(numbers[i]);
    }
    
    dfs(arr[0],1,target);
    dfs(-arr[0],1,target);
    answer = cnt;
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// int counter = 0;

// void dfs(int current, int depth, int target, vector<int> arr){
//     if(depth==arr.size()){
//         if(current==target){
//             counter++;
//         }
//         return;
//     }
    
//     dfs(current+arr[depth],depth+1,target,arr);
//     dfs(current-arr[depth],depth+1,target,arr);
    
// }
// int solution(vector<int> numbers, int target) {
    
//     dfs(numbers[0],1,target,numbers);
//     dfs(-1*numbers[0],1,target,numbers);
//     return counter;
// }
