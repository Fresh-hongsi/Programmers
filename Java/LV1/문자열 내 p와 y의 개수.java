class Solution {
    boolean solution(String s) {
        boolean answer = true;

        Integer pCount = 0;
        Integer yCount = 0;
        
        s= s.toLowerCase();
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='p'){
                pCount++;
            }
            
            if(s.charAt(i)=='y'){
                yCount++;
            }
        }
        
        if(pCount==yCount){
            answer=true;
        }
        else{
            answer=false;
        }

        return answer;
    }
}
