import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        
        PriorityQueue<Integer> min_heap = new PriorityQueue<>(); // 오름차순 큐
        PriorityQueue<Integer> max_heap = new PriorityQueue<>(Collections.reverseOrder()); // 내림차순 큐
        
        // 연산과 값 받아서 구분하기
        for(int i=0;i<operations.length;i++){
            String s = operations[i];
            String[] sp = s.split(" ");
            String op = sp[0];
            Integer num = Integer.parseInt(sp[1]);
            
            // I 연산일 경우, 최소힙, 최대힙에 모두 넣기
            if(op.equals("I")){
                min_heap.add(num);
                max_heap.add(num);
            }
            
            // 삭제 연산일 경우
            else if(op.equals("D")){
                if(num==1){ // 최대힙에서 제거
                    
                    if(!max_heap.isEmpty()){
                        int maximum = max_heap.peek();
                        max_heap.poll();
                        
                        // 최대힙에 제거할 값을 최소힙에서도 삭제
                        if(!min_heap.isEmpty()){
                            min_heap.remove(maximum); // REMOVE(VALUE) -> 특정 값으로 제거
                        }
                        
                    }

                }
                
                if(num==-1){ // 최소힙에서 제거
                    if(!min_heap.isEmpty()){
                        int minimum = min_heap.peek();
                        min_heap.poll();
                        // 최소힙에서 제거할 값을 최대힙에서도 삭제
                        if(!max_heap.isEmpty()){
                            max_heap.remove(minimum);
                        }
                        
                    }                    
                }
            }
            

        }
        
        // 비어있는 큐가 있다면, [0,0]
        if(max_heap.size()==0 || min_heap.size()==0){
            answer[0]=0;
            answer[1]=0;
        }
        // 비어있지 않다면 값 넣어주기
        else{
            answer[0]=max_heap.peek();
            answer[1]=min_heap.peek();
        }

        return answer;
    }
}

//   333 45 -45 -642 
//  -45 45 97 333 653 
