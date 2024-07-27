import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        HashMap<String,Integer> hm = new HashMap<>();
        
        for(int i=0;i<name.length;i++){
            String curName = name[i];
            int score = yearning[i];
            
            hm.put(curName,score);
        }
        
        for(int i=0;i<photo.length;i++){
            
            int sum = 0;
            for(int j=0;j<photo[i].length;j++){
                String curName = photo[i][j];
                if(hm.containsKey(curName)){
                    sum+=hm.get(curName);
                }
            }
            answer[i]=sum;
        }
        
//         for(Map.Entry<String,Integer> k : hm.entrySet()){
//             String key = k.getKey();
//             Integer value = k.getValue();
            
//             System.out.println(key+' '+value);
//         }
        
        return answer;
    }
}
