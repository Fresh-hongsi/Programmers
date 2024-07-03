import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = Long.toString(n);
        Character[] chars = new Character[s.length()];
        
        for(int i=0;i<s.length();i++){
            chars[i] = s.charAt(i);
        }
        
        Arrays.sort(chars,Collections.reverseOrder());
        
        StringBuilder sb = new StringBuilder(chars.length);
        for(char c:chars){
            sb.append(c);
        }
        
        answer = Long.parseLong(sb.toString());
        return answer;
    }
}
