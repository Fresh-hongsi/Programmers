import java.util.*;

class Solution {
    
    
    public boolean[] visited = new boolean[200];
    public ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
    
    public void bfs(int start){
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        visited[start]=true;
        
        while(!q.isEmpty()){
            int cur = q.peek();
            q.poll();
            
            for(int k : adjList.get(cur)){
                if(visited[k]==false){
                    q.add(k);
                    visited[k]=true;
                }
            }
        }
        
    }
    
    public void dfs(int start){
        visited[start]=true;
        
        for(int k : adjList.get(start)){
            if(visited[k]==false){
                dfs(k);
        
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        for(int i=0;i<n;i++){
            adjList.add(new ArrayList<Integer>());
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(computers[i][j]==1){
                    if(i!=j){
                        adjList.get(i).add(j);
                        adjList.get(j).add(i);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                bfs(i);
                //dfs(i);
                answer++;
            }
        }
        
        return answer;
    }
}
