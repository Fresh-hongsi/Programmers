class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        
        long min = (long)Math.min(a,b);
        long max = (long)Math.max(a,b);
        for(long i=min;i<=max;i++){
            answer+=i;
        }
        return answer;
    }
}
