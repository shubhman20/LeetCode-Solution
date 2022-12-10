class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long n,int x){
        if(n==0)    return 1;
        long long temp = power(n/2,x)%mod;
        temp = (temp*temp)%mod;
        if(n%2==0)
            return temp%mod;
        return (temp*x)%mod;
    }
    int countGoodNumbers(long long n){
        long long ans=1;
        long long odd = n/2;
        long long even = n/2 + n%2;
        ans = (power(even,5)*power(odd,4))%mod;
        return ans%mod;
    }
};
