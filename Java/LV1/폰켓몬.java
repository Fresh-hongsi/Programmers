import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        HashMap<Integer,Integer> hm = new HashMap<>();
        
        for(int i=0;i<nums.length;i++){
            int cur = nums[i];
            if(hm.containsKey(cur)){
                int value = hm.get(cur);
                value+=1;
                hm.put(cur,value);
            }
            else{
                hm.put(cur,1);
            }
        }
        
        if(nums.length/2 > hm.size()){
            answer = hm.size();
        }
        else{
            answer = nums.length/2;
        }
        return answer;
    }
}

// 1:1
// 2:5
// 3:2
