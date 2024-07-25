import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        
        for(int i=0;i<phone_book.length-1;i++){
            String front = phone_book[i];
            String second = phone_book[i+1];
            
            if(second.length()>=front.length()){
                String subSecond  = second.substring(0,front.length());
                if(front.compareTo(subSecond)==0){
                    answer=false;
                    break;
                }
            }
        }

        return answer;
    }
}
