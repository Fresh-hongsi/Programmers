import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        int[][] dp = new int[triangle.length][triangle.length];
        Integer[] result = new Integer[triangle[triangle.length-1].length]; // 정렬할 때 Integer객체 타입 넣기 조심!
 
        int idx = 0;
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0]+triangle[1][0];
        dp[1][1] = dp[0][0]+triangle[1][1];
        
        for(int i=2;i<triangle.length;i++){
            for(int j=0;j<triangle[i].length;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                else if(j==triangle[i].length-1){
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                else{
                    dp[i][j]=Math.max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                }
                
                if(i==triangle.length-1){
                    result[idx++]=dp[i][j];
                }
            }
        }
        
        Arrays.sort(result,Collections.reverseOrder());
        answer= result[0];
        return answer;
    }
}
