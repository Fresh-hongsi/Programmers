import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String temp = "";
        int counter = 0;
        ArrayList<Integer> al = new ArrayList<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' '){
                al.add(Integer.parseInt(temp));
                temp="";
                counter++;
                
            }
            else{
                temp+=s.charAt(i);
            }
        }
        al.add(Integer.parseInt(temp));
        
        Collections.sort(al,Collections.reverseOrder());
        String max = Integer.toString(al.get(0));
        String min = Integer.toString(al.get(counter));
        
        answer+=min;
        answer+=" ";
        answer+=max;
        return answer;
    }
}
