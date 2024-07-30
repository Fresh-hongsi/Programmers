import java.util.*;
class Pair {
    int x;
    double y;
    
    public Pair(int a, double b){
        x = a;
        y = b;
    }
}

class Solution {
    
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        HashMap<Integer,Integer> hm = new HashMap<>();
        int total = stages.length;
        ArrayList<Pair> ap = new ArrayList<>();
        
        // 스테이지 별 도달 인원 현황 세팅
        for(int i=1;i<=N+1;i++){
            hm.put(i,0);
        }
        for(int i=0;i<stages.length;i++){
            int curStage = stages[i];
            int curValue = hm.get(curStage);
            hm.put(curStage,curValue+1);
            
        }
        
        // 각 스테이지 별 실패율을 계산해서 pair의 배열에 저장
        for(int i=1;i<=N;i++){
            if(total!=0){
                double score = ((double)(hm.get(i)))/((double)total);
                ap.add(new Pair(i,score));    
            }
            else{
                double score = 0;
                ap.add(new Pair(i,score));    
            }
            
            total-=(hm.get(i));
        }
        
        
        Collections.sort(ap,new Comparator<Pair>(){
            @Override
            public int compare(Pair p1, Pair p2){
                if(p1.y!=p2.y){
                    return Double.compare(p2.y,p1.y); // 실패율이 높은 순서대로
                }
                else{
                    return Integer.compare(p1.x,p2.x); // 그게 아니라면 스테이지순대로
                }
            }
        });
        
        for(int i=0;i<N;i++){
            answer[i]=ap.get(i).x;
        }
        return answer;
    }
}

// 1:1 1/8
// 2:3 3/7
// 3:2 2/4
// 4:1 1/2
// 5:0 0/1
// 6:0 0/0
