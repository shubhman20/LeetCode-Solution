class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int f=0,s=1,t=1;
        while(n>=3){
            int temp = t;
            t +=f+s;
            f=s;s=temp;
            n--;
        }
        return t;
    }
};
