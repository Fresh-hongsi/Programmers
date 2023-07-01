#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr; //오름차순 정렬하기 위한 배열
    string temp=""; //공백 나오기 전까지 저장할 임시 문자열
    bool flag=true; //true: 양수 false:음수
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ' )//공백일 경우 temp에 있던 문자열을 정수화 시켜 arr에 저장
        {
            int cur=stoi(temp);
            if(flag==true) //양수일 경우
            {
                arr.push_back(cur);    
            }
            
            else //음수일 경우
            {
                arr.push_back(cur*-1);
            }
            
            flag=true; //다시 초기 세팅 -> 양수가 들어올 것으로 기대
            temp=""; //임시 문자열 초기화
            
        }
        
        else if(s[i]=='-') //만약 -가 들어온 경우 음수로 설정
        {
            flag=false;
        }
        
        else //2자리 이상의 숫자가 들어오는 경우 임시 문자열에 추가
        {
            temp+=s[i];
        }
    }
    
    //문자열 끝까지 도달한 경우 여태까지 저장된 temp를 arr에 넣어준다
    int cur=stoi(temp);
    if(flag==true)
    {
        arr.push_back(cur);    
    }
            
    else
    {
        arr.push_back(cur*-1);
    }
    
    
    sort(arr.begin(),arr.end());
    answer+=to_string(arr[0]);
    answer+=" ";
    answer+=to_string(arr[arr.size()-1]);
    return answer;
}
