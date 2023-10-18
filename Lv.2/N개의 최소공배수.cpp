#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 두 개의 lcm을 구한 후, 스택에 넣어주는 과정을 반복함으로써 최종 lcm을 구하는 로직

int solution(vector<int> arr) {
    
    stack<int> st; // 스택 선언
    
    for(int i=0;i<arr.size();i++) // 스택에 담아줌
    {
        st.push(arr[i]);
    }
    
    // 스택에 두 개 이상 남아있을 때까지 반복
    while(st.size()>1)
    {
        // 좌항
        int a= st.top();
        st.pop();
        
        // 우항
        int b= st.top();
        st.pop();
        
        // 최대공약수
        int r= 1;
        
        // 최대공약수 구하기
        for(int j=1;j<=min(a,b);j++)
        {
            if(a%j==0 && b%j==0)
            {
                r=j;
            }
        }
        
        // 두 수의 최소공배수를 스택에 넣어주기
        st.push(r*(a/r)*(b/r));
    }
    
    // 스택에 마지막으로 남은 수 하나가 최종 최소공배수임
    int answer = st.top();
    st.pop();
    return answer;
}
