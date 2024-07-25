import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String,Integer> hm = new HashMap<>();
        
        for(int i=0;i<clothes.length;i++){
            String val = clothes[i][0];
            String key = clothes[i][1];
            
            if(hm.containsKey(key)){
                int value = hm.get(key);
                hm.put(key,value+1);
            }
            else{
                hm.put(key,1);
            }
        }
        
        for(Map.Entry<String,Integer> k : hm.entrySet()){
            String curKey = k.getKey();
            Integer curValue = k.getValue();
            answer*=(curValue+1);
            
        }
        answer-=1;
        return answer;
    }
}
