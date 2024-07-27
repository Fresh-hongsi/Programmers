import java.util.*;

class Solution {
    public String solution(int a, int b) {
        String answer = "";
        int[] cal = {31,29,31,30,31,30,31,31,30,31,30,31};
        String[] day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
        int total = 0;
        for(int i=0;i<a-1;i++){
            total+=cal[i];
        }
        total+=b;
        total-=1;
        // 1/1 금
        // 1/2 토
        // 1/3 일
        // 1/4 월
        // 1/5 화
        // 1/6 수
        // 1/7 목
        // 1/8 금
        
        System.out.println(total);
        int k = total%=7;
        answer = day[k];
        return answer;
    }
}

