import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        String[] sArr= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        for(int i=0;i<sArr.length;i++){
            if(s.contains(sArr[i])){
                s = s.replace(sArr[i], Integer.toString(i));
            }
        }
        
        answer = Integer.parseInt(s);
        return answer;
    }
}
