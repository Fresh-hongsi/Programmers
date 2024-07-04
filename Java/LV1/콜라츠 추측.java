class Solution {
    public int solution(int num) {
        int answer = 0;
        int counter = 0;
        long number = (long)num;
        while(true){
            
            if(number==1){
                answer=counter;
                break;
            }
            
            if(counter>=500){
                answer=-1;
                break;
            }
            
            if((number%2==0)){
                number/=2;
            }
            else{
                number*=3;
                number+=1;
            }
            
            counter++;
        }
        return answer;
    }
}
