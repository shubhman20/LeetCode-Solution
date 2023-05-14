class Solution {
public:
    int f(vector<int>&nums,int op,int mask,vector<int>&dp){
        int m = nums.size();
        int n = nums.size()/2;
        if(op>n) return 0;
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<m;i++){
            if(mask & (1<<i)) continue;
            for(int j=i+1;j<m;j++){
                if(mask & (1<<j)) continue;
                int newMask = (1<<i)|(1<<j)|mask;
                int val = op*__gcd(nums[i],nums[j]) + f(nums,op+1,newMask,dp);
                dp[mask] = max(dp[mask],val);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14,-1);
        return f(nums,1,0,dp);
    }
};
