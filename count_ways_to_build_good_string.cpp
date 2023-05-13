//Recursion 
int mod = 1e9+7;
    int f(int l,int h,int zero,int one,int size){
        if(size==h) return 1;
        int z=0,o=0;
        if(size+zero<=h) z = f(l,h,zero,one,size+zero);
        if(size+one<=h) o = f(l,h,zero,one,size+one);

        if(size+one>=l && size+one<h) o++;
        if(size+zero>=l && size+zero<h) z++;
        return (z+o)%mod;
    }

//Memoization
    int f(int l,int h,int zero,int one,int size,vector<int>&dp){
        if(size==h) return 1;
        if(dp[size]!=-1) return dp[size];
        int z=0,o=0;
        if(size+zero<=h) z = f(l,h,zero,one,size+zero,dp);
        if(size+one<=h) o = f(l,h,zero,one,size+one,dp);

        if(size+one>=l && size+one<h) o++;
        if(size+zero>=l && size+zero<h) z++;
        return dp[size]=(z+o)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return f(low,high,zero,one,0,dp);
    }

//Tabulation
int f(int l,int h,int zero,int one,int size,vector<int>&dp){
        dp[size]=1;
        for(int i=size-1;i>=0;i--){
            int z=0,o=0;
            if(i+zero<=h) z = dp[i+zero];
            if(i+one<=h) o = dp[i+one];

            if(i+one>=l && i+one<h) o++;
            if(i+zero>=l && i+zero<h) z++;
            dp[i] = (z+o)%mod;
        }
        return dp[0];
    }
