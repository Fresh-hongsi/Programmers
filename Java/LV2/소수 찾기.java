import java.util.*;
class Solution {
    
    String s = "";
    boolean[] visited;
    HashSet<Integer> hs = new HashSet<>();
    
    public int solution(String numbers) {
        int answer = 0;
        s=numbers;
        visited = new boolean[s.length()];
        
        // 모든 순열을 구해보고, 해당 순열 순서에 맞는 인덱스를 문자열로 만들어서 hashSet에 넣어줌
        for(int i=1;i<=s.length();i++){
            bt("",i,0,visited);
            visited = new boolean[s.length()];
        }
        
        
        
        //각 숫자에 대해 소수인지 판별 시도
        for(Integer k : hs){
            //System.out.println(k);
            boolean flag = isPrime(k);
            if(flag==true){
                System.out.println(k);
                answer++;
            }
        }
        
        return answer;
    }
    
    // 소수찾기
    public boolean isPrime(Integer cur){
        
        boolean flag = true;
        if(cur<2){
            flag=false;
        }
        for(int i=2;i*i<=cur;i++){
            if(cur%i==0){
                flag= false;
            }
        }
        
        return flag;
    }
    
    // 백트래킹 통한 순열
    // cur: 현재 문자열 depth: 현재 깊이 visit: 방문표시 배열
    public void bt(String cur,int target, int depth, boolean[] visit){
        if(depth==target){ // 만약 최대 깊이에 도달했다면 set에 넣어줌
            hs.add(Integer.parseInt(cur));
            //System.out.println(cur);
        }
        else{
            for(int i=0;i<s.length();i++){
                if(visit[i]==false){ // 아직 안가본 곳이라면
                    String next = cur+s.charAt(i); // 해당 인덱스를 문자열에 추가
                    visit[i]=true; // 방문 표시
                    bt(next,target,depth+1,visit); // 다음 깊이 시도
                    visit[i]=false;
                }
                
                
            }
            
        }
    }
}
