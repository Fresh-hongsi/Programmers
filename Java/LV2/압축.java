import java.util.*;

class Solution {
    public int[] solution(String msg) {
        ArrayList<Integer> result = new ArrayList<>();
        int[] answer = {};
        
        HashMap<String,Integer> hm = new HashMap<>();
        String s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0;i<26;i++){
            hm.put(Character.toString(s.charAt(i)),i+1);
        }
        
//         for(Map.Entry<String,Integer> k : hm.entrySet()){
//             System.out.print(k.getKey());
//             System.out.print(" ");
//             System.out.println(k.getValue());
            
//         }
        
        Integer idxNum = 27; // 새롭게 등재될 문자열의 번호
        Integer curIdx = 0; // 현재 참조하고 있는 인덱스값
        
        String w = "";
        w+=msg.charAt(curIdx);
        
        
        while(curIdx<msg.length()){
            if(hm.containsKey(w)==true){ // 다음 거 참조 시도
                if(curIdx==msg.length()-1){ // 이 조건 매우 중요!!!
                    break;
                }
                curIdx++;
                w+=msg.charAt(curIdx);
            }
            else{ // 가장 최근 거 출력, 현재 거 사전 추가
                String copy = w;
                Integer wLength = w.length();
                
                result.add(hm.get(copy.substring(0,wLength-1)));
                //System.out.println(copy.substring(0,wLength-1));
                hm.put(w,idxNum++);
                w = "";
                w+=msg.charAt(curIdx);
            }
        }
        result.add(hm.get(w));
        int arrSize = 0;
        for(int i=0;i<result.size();i++){
            if(result.get(i)!=0){
                arrSize++;
            }
        }
        answer=new int[arrSize];
        for(int i=0;i<arrSize;i++){
            answer[i]=result.get(i);
        }
        return answer;
    }
}
