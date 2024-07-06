import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] copy = new int[arr.length]; // arr을 복사한 값을 저장할 배열 -> 정렬 위해 사용
        int[] answer = new int[arr.length-1]; // 실제 정답을 저장할 배열
        
        int min = 0; // 최솟값
        
        // arr의 값을 copy에 복사
        for(int i =0;i<arr.length;i++)
        {
            copy[i]=arr[i];
        }
        
        // 오름차순 정렬
        Arrays.sort(copy);
        min = copy[0];
        
        // 최솟값이 아닌 것만 answer에 저장
        int idx=0;
        for(int i =0;i<arr.length;i++)
        {
            if(arr[i]!=min){
                answer[idx]=arr[i];
                idx++;
            }
        }
        
        // 만약 최솟값을 제거한 후 배열의 크기가 0이라면 직접 -1넣은 배열을 할당
        if(answer.length==0){
            answer = new int[1];
            answer[0]=-1;
        }
        return answer;
    }
}
