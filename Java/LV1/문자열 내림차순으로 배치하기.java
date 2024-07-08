import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        Character arr[] = new Character[s.length()];
        for(int i=0;i<s.length();i++){
            arr[i]=s.charAt(i);
        }
        Arrays.sort(arr,Collections.reverseOrder());
        for(int i=0;i<arr.length;i++){
            answer+=arr[i];
        }
        
        return answer;
    }
}
