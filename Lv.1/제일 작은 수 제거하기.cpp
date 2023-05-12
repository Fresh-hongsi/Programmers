#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> temp; //arr과 똑같은 값을 지닌 임시 배열
    
    for(int i=0;i<arr.size();i++) //arr와 똑같은 값을 지니도록 temp 배열 초기화
    {
        temp.push_back(arr[i]);
    }
    
    sort(temp.begin(),temp.end()); //temp배열을 오름차순 정렬
    int min=temp[0]; //가장 작은 원소 찾기
    
    if(arr.size()>1) //만약 arr 배열의 크기가 1보다 크다면
        
    {
        int idx=find(arr.begin(),arr.end(),min)-arr.begin(); //min값을 지닌 arr의 idx위치를 찾아서
        
        arr.erase(arr.begin()+idx); //지워준다
    }
    
    else //만일 arr 배열의 크기가 1개라면
    {
       int idx=find(arr.begin(),arr.end(),min)-arr.begin(); //min값을 지닌 arr의 idx위치를 찾아서
        
        arr.erase(arr.begin()+idx); //지워주고
        arr.push_back(-1); //-1을 넣어준다
    }
    
    for(int i=0;i<arr.size();i++) //arr의 배열을 answer배열에 똑같이 넣어주기
    {
        answer.push_back(arr[i]);
    }
    
    
    return answer;
}
