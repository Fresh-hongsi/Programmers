import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        String s1 = "12345";
        String s2 = "21232425";
        String s3 = "3311224455";
        
        while(s1.length()<10000){
            s1+=s1;
        }
        
        while(s2.length()<10000){
            s2+=s2;
        }
        
        while(s3.length()<10000){
            s3+=s3;
        }
        
        int sum1=0;
        int sum2=0;
        int sum3=0;
        
        for(int i=0;i<answers.length;i++){
            if(answers[i]==s1.charAt(i)-'0'){
                sum1++;
            }
            
            if(answers[i]==s2.charAt(i)-'0'){
                sum2++;
            }
            
            if(answers[i]==s3.charAt(i)-'0'){
                sum3++;
            }
        }
        
        int maximum = Math.max(sum1,sum2);
        maximum = Math.max(maximum,sum3);
        
        int k=0;
        if(maximum==sum1){
            k++;
        }
        if(maximum==sum2){
            k++;
        }
        if(maximum==sum3){
            k++;
        }
        
        answer = new int[k];
        int s=0;
        if(maximum==sum1){
            answer[s++]=1;
        }
        if(maximum==sum2){
            answer[s++]=2;
        }
        if(maximum==sum3){
            answer[s++]=3;
        }
        return answer;
    }
}
