class Solution {
public:
    double impPow(double x,int n){
        if(n==0)
            return 1;
            double temp = impPow(x,n/2);
            temp = temp*temp;
            if(n%2==0)
                return temp;
            return temp*x; 
    }
    double myPow(double x, int n) {
        double ans;
        int p = abs(n);
        ans=impPow(x,p);
        if(n<0){
            return (double)1/ans;
        }
        return ans;
    }
};
