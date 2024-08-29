import java.util.*;

class Pair {
    int first;
    int second;
    
    Pair(int a, int b){
        this.first = a;
        this.second = b;
    }
}

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        ArrayList<Pair> r = new ArrayList<Pair>();
        
        for(int i=0;i<routes.length;i++){
            Integer in = routes[i][0];
            Integer out = routes[i][1];
            
            r.add(new Pair(in,out));
        }
        
        Collections.sort(r, new Comparator<Pair>(){
            @Override
                public int compare(Pair a, Pair b){
                    if(a.second==b.second){ // second가 같다면, first 빠른 순
                        if(a.first<b.first){
                            return -1;
                        }
                        else{
                            return 1;
                        }
                    }
                    else{ // second가 다르다면 second 빠른 순
                        if(a.second<b.second){
                            return -1;
                        }
                        else{
                            return 1;
                        }
                    }
                }
        });
        
        answer =1;
        int cur = r.get(0).second;
        
        for(int i=1;i<r.size();i++){
            if(r.get(i).first<=cur){
                continue;
            }
            else{
                answer++;
                cur = r.get(i).second;
            }
            
        }
        
        
        return answer;
    }
}

// -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 -0
// 	-------
// --------------------------  
//             -------------------------
// 				  -------------------------------------
// 									    ---------


// --------------------------  
//             -------------------------
// 				  -------------------------------------
// 	
