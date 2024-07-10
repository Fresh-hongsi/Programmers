import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
       
        for(int i=0;i<commands.length;i++){
            int [] cur = Arrays.copyOfRange(array,commands[i][0]-1,commands[i][1]);
            // int count = 0;
            // for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++){
            //     cur[count++]=array[j];
            // }
            
            Arrays.sort(cur);
            answer[i]=cur[commands[i][2]-1];
        }
        return answer;
    }
}
