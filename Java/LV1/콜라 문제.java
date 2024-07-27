import java.util.*;

class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        
        while(n>=a){
            int temp = (n/a);
            answer += temp*b;
            n+=temp*b;
            n-=temp*a;
        }
        return answer;
    }
}

// 20 -> 10
// 0+10 -> 5
// 0+5 -> 2
// 1+2 -> 1
// 1+1 -> 1

// 3개 주면 2개
// 20 -> 6*2
// 20-(3*6)+12 -> 2
// 2+2 -> 1
// 1+1 
