import java.util.*;

class Solution {

    public int counter = 51;
    public boolean[] visited = new boolean[51];
    public boolean flag = false;
    public LinkedList<String> seq = new LinkedList<>();
    public void backtracking(String cur, String target, Integer depth, String[] word){
        
        if(cur.equals(target)){
            flag = true;

            if(depth<counter){
                counter = depth;
            }
            return;
        }
        
        for(int i = 0;i<word.length;i++){
            int cnt = 0;
            
            if(visited[i]==false){
                for(int j=0;j<word[i].length();j++){
                    if(word[i].charAt(j)==cur.charAt(j)){
                        cnt++;
                    }
                }
                if(cnt==cur.length()-1){
                    visited[i]=true;
                    backtracking(word[i],target,depth+1,word);
                    visited[i]=false;
                    
                }
            }
            
        }
            
            
    }
    

    public int solution(String begin, String target, String[] words) { 
        
        for(int i=0;i<visited.length;i++){
            visited[i]=false;
        }
        
        backtracking(begin,target,0,words);
        if(flag == false){
            counter = 0;
        }
        return counter;
    }
}
