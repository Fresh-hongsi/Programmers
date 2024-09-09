import java.util.*;

class Pair {
    int first;  // 목적지 공항 번호
    boolean second;  // 방문 여부

    Pair(int first, boolean second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    ArrayList<ArrayList<Pair>> adjList = new ArrayList<>();
    HashMap<String,Integer> hm = new HashMap<>();
    ArrayList<Integer> tempAnswer = new ArrayList<>();
    ArrayList<String> airport = new ArrayList<>();
    HashSet<String> hs = new HashSet<>();
    Integer counter = 1;
    boolean flag = false;
    
    public void backtracking(int cur){
        if(tempAnswer.size() == counter){
            flag = true;
            return;
        }
        
        for(Pair k : adjList.get(cur)){
            if(k.second == false){
                k.second=true;
                tempAnswer.add(k.first);
                backtracking(k.first);
                
                if(flag == true){
                    return;
                }
                else{
                    tempAnswer.remove(tempAnswer.size()-1); // 마지막 요소 삭제
                    k.second = false;
                }
            }
        }
    }
    public String[] solution(String[][] tickets) {
        
        for(int i=0;i<10000;i++){
            adjList.add(new ArrayList<>());
        }
        
         // 모든 공항을 리스트에 추가 (중복 포함)
        ArrayList<String> allAirports = new ArrayList<>();
        for(int i = 0 ;i<tickets.length;i++){
            String start = tickets[i][0];
            String end = tickets[i][1];
            
            allAirports.add(start);
            allAirports.add(end);
        }
        
        // 공항 목록을 정렬하고 중복 제거
        Collections.sort(allAirports);
        
        // LinkedHashSet을 사용하여 순서를 유지하면서 중복 제거
        LinkedHashSet<String> uniqueAirports = new LinkedHashSet<>(allAirports);
        airport.addAll(uniqueAirports);
        
        // 공항 이름에 인덱스 매핑
        for(int i=0;i<airport.size();i++){
            hm.put(airport.get(i),i);
        }
        
        // 인접리스트 세팅
        for(int i = 0 ;i<tickets.length;i++){
            String start = tickets[i][0];
            String end = tickets[i][1];
            
            adjList.get(hm.get(start)).add(new Pair(hm.get(end),false));
            counter++;
        }
        
        // 정렬
        for(int i = 0 ;i<adjList.size();i++){
           
            adjList.get(i).sort((a,b) -> a.first - b.first);
        }
        
        // 백트래킹 시도
        tempAnswer.add(hm.get("ICN"));
        backtracking(hm.get("ICN"));
        
        // 정답 만들기
        String[] answer = new String[tempAnswer.size()];
        for(int i=0;i<answer.length;i++){
            answer[i]=airport.get(tempAnswer.get(i));
        }
        
        return answer;
    }
}
