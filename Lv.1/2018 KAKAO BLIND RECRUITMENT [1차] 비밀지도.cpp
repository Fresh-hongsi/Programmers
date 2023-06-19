#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer; //답으로 return할 string 배열
    for(int i=0;i<n;i++) //arr1, arr2의 행만큼 반복
    {
        string a=""; //arr1[i]에서의 int를 지도에 따라 공백, #으로 변환되어 저장될 문자열 
        string b=""; //arr2[i]에서의 int를 지도에 따라 공백, #으로 변환되어 저장될 문자열
        
        //arr1[i], arr2[i]의 int를 보고 /2씩하여 나머지가 1이면 #, 0이면 공백으로 변환
        //추후에 a,b는 역순으로 뒤집어야 목표로 하고자 하는 문자열이 됨을 기억하자
        for(int j=0;j<n;j++) 
        {
            if(arr1[i]%2==1)
            {
                a+="#";
                arr1[i]/=2;
            }
            
            else
            {
                a+=" ";
                arr1[i]/=2;
            }
            
            if(arr2[i]%2==1)
            {
                b+="#";
                arr2[i]/=2;
            }
            else
            {
                b+=" ";
                arr2[i]/=2;
            }
        }
        
        reverse(a.begin(),a.end()); //a문자열 뒤집기
        reverse(b.begin(),b.end()); //b문자열 뒤집기
        string c=""; //문자열 a와 b를 구분하여 둘 다 공백일 경우만 공백처리, 이외의 경우엔 #처리
        for(int j=0;j<n;j++)
        {
            if(a[j]==' ' && b[j]==' ' )
            {
                c+=" ";
            }
            else
            {
                c+="#";
            }
        }
        answer.push_back(c);
    }
    return answer;
}
