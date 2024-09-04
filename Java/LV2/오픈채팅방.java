import java.util.*;

class Pair{
    String first;
    String second;
    
    Pair(String x, String y){
        first=x;
        second=y;
    }
}

class Solution {
    public String[] solution(String[] record) {
        String[] answer;
        
        ArrayList<Pair> cmdId = new ArrayList<Pair>();
        HashMap<String,String> idName = new HashMap<>();
        
        for(int i=0;i<record.length;i++){
            String s = record[i];
            String[] temp = s.split(" ");
            
            String cmd = temp[0];
            String id = temp[1];
            String name = "";
            
            if(!cmd.equals("Leave")){
                name = temp[2];
            }
            
            if(cmd.equals("Enter")){
                
                idName.put(id,name);
                cmdId.add(new Pair(cmd,id));
            }
            else if(cmd.equals("Leave")){
                cmdId.add(new Pair(cmd,id));
            }
            else{
                
                idName.put(id,name);
            }
            
            
            
            
        }
        answer = new String[cmdId.size()];
            for(int i=0;i<cmdId.size();i++){
                if(cmdId.get(i).first.equals("Enter")){
                    String tempName = idName.get(cmdId.get(i).second);
                    answer[i]=tempName+"님이 들어왔습니다.";  
                }
                else if(cmdId.get(i).first.equals("Leave")){
                    String tempName = idName.get(cmdId.get(i).second);
                    answer[i]=tempName+"님이 나갔습니다.";
                }
                
            }
        return answer;
        
        
    }
}
