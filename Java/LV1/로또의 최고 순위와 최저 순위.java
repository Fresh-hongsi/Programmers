import java.util.*;
class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        HashMap<Integer,Integer> scoreMap = new HashMap<>(); // <일치 숫자 개수 : 순위> 저장 맵
        HashSet<Integer> winNumMap = new HashSet<>(); // 당첨번호 관리 set
        int[] answer = new int[2];
        
        scoreMap.put(0,6);
        scoreMap.put(1,6);
        scoreMap.put(2,5);
        scoreMap.put(3,4);
        scoreMap.put(4,3);
        scoreMap.put(5,2);
        scoreMap.put(6,1);
        
        for(int i=0;i<win_nums.length;i++){
            int curNum = win_nums[i];
            winNumMap.add(curNum);
        }
        
        int count=0; // 일치하는 숫자 개수
        int zeroCount = 0; // 0의 개수
        for(int i=0;i<lottos.length;i++){
            int curNum = lottos[i];
            if(winNumMap.contains(curNum)){
                count++;
            }
            else if(curNum==0){
                zeroCount++;
            }
        }
        
        answer[0] = scoreMap.get(count+zeroCount);
        answer[1] = scoreMap.get(count);
        return answer;
    }
}
