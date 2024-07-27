import java.util.*;

class Solution {
    
    public String decode(int k,int n){

        String result = "";
        while(k>0){
            result+=Integer.toString(k%2);
            k/=2;
        }
        
        while(result.length()<n){
            result+="0";
        }
        
        StringBuffer sb = new StringBuffer(result);
        result = sb.reverse().toString();
        //System.out.println(result);
        return result;
    }
    
    public String fusion(String s1, String s2){
        
        String result = "";
        
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i)=='1' || s2.charAt(i)=='1'){
                result+="#";
            }
            else{
                result+=" ";
            }
        }
        
        return result;
    }
    
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for(int i=0;i<n;i++){
            int i1 = arr1[i];
            int i2 = arr2[i];
            
            String s1 = decode(i1,n);
            String s2 = decode(i2,n);
            
            String r = fusion(s1,s2);
            answer[i]=r;
        }
        return answer;
    }
}
