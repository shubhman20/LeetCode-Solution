class Solution {
public:
long long mod = 1e9+7;
    int numTilings(int n) {
        vector<int> dp(n+1,0);
        if(n==1||n==2) return n;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i] = ((dp[i-1]*2)%mod + dp[i-3])%mod;
        }
        return dp[n];
    }
};
