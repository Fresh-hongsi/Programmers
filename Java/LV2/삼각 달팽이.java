import java.util.*;

class Solution {
    public int[] solution(int n) {
        
        int[] answer = {}; // 최종 값
        int[][] arr = new int[n][n]; // 값 값을 저장할 이차원 배열
        int startSize = n; // 지도의 길이
        int k = 1; // 추적 값
        int counter = 0; // 계산 옵션
        int totalCount = 0; // 전체 요소가 몇개인지 추적
        
        int r = -1;
        int c = 0;
        
        while(n>0){
            if(counter==0){
                counter++;
                
                for(int i=0;i<n;i++){
                    arr[++r][c]=k++;
                    totalCount++;
                }
                n--;
                continue;
            }
            else if(counter == 1){
                counter++;
                
                for(int i=0;i<n;i++){
                    arr[r][++c]=k++;
                    totalCount++;
                }
                n--;
                continue;
            }
            else{
                counter = 0;
                
                for(int i=0;i<n;i++){
                    arr[--r][--c]=k++;
                    totalCount++;
                }
                n--;
                continue;
            }
        }
        
        answer = new int[totalCount];
        int idx = 0;
        for(int i=0;i<startSize;i++){
            for(int j=0;j<=i;j++){
                answer[idx++]=arr[i][j];
                
            }
        }
    
        
        return answer;
    }
}
