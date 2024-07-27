import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        List<Integer> temp = new ArrayList<>();
        temp.add(arr[0]);
        int cur = arr[0];
        for(int i=1;i<arr.length;i++){
            if(cur==arr[i]){
                continue;
            }
            else{
                temp.add(arr[i]);
                cur=arr[i];
            }
        }

        answer = new int[temp.size()];
        for(int i=0;i<temp.size();i++){
            answer[i]=temp.get(i);
        }
        return answer;
    }
}
