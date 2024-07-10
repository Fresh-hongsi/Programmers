class Solution {
    public String solution(String s, int n) {
        
        String answer = "";
        
        n%=26;
        
        for(int i=0;i<s.length();i++){
        
            char ch = s.charAt(i);
//             System.out.println((int)'a');
//             System.out.println((int)'z');
            
//             System.out.println((int)'A');
//             System.out.println((int)'Z');
            if(Character.isLowerCase(ch)){
                ch = (char)('a'+((ch-'a')+n)%26);
            }
            
            if(Character.isUpperCase(ch)){
                ch = (char)('A'+((ch-'A')+n)%26);
                
                // 97 122
                // 97+(100+24)
            }
            
            answer+=ch;
        }
        
        return answer;
    }
}
