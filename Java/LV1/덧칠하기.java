import java.util.*;

class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        //01234567891011
        boolean[] wall = new boolean[n+m];
        for(int i=0;i<n+m;i++){
            wall[i]=true;
        }
        for(int i=0;i<section.length;i++){
            int cur = section[i];
            wall[cur-1]=false;
        }
        
        for(int i=0;i<n;i++){
            if(wall[i]==false){
                answer++;
                for(int j=i;j<i+m;j++){
                    wall[j]=true;
                }
            }
        }
        return answer;
    }
}
