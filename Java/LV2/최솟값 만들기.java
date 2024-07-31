import java.util.*;

class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;
        Integer[] a = new Integer[A.length];
        Integer[] b = new Integer[B.length];
        
        for(int i=0;i<A.length;i++){
            a[i]=A[i];
            b[i]=B[i];
        }
        
        Arrays.sort(a);
        Arrays.sort(b,Collections.reverseOrder());
        
        for(int i=0;i<a.length;i++){
            answer+=(a[i]*b[i]);
        }
        return answer;
    }
}
 
