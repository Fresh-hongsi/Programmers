import java.util.*;

class Pair{
    int first;
    int second;
    
    Pair(int a, int b){
        first=a;
        second=b;
    }
}
class Solution {
    
    int counter = -1;
    
    public void bfs(int x, int y, int n){
        
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(y,0));
        
        while(!q.isEmpty()){
            int cur = q.peek().first;
            int len = q.peek().second;
            q.poll();
            if(cur==x){
                counter = len;
                break;
            }
            
            if(cur-n>=x){
                q.add(new Pair(cur-n,len+1));
            }
            
            if(cur%2==0 && cur/2>=x){
                q.add(new Pair((cur/2),len+1));
            }
            
            if(cur%3==0 && cur/3>=x){
                q.add(new Pair((cur/3),len+1));
            }
        }
    }
    public int solution(int x, int y, int n) {
        bfs(x,y,n);
        return counter;
    }
}
