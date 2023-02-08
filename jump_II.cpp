class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> dp(nums.size(),-1);
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=nums.size()-1){
                dp[i] = 1;
            }
            else{
                int mini=nums.size();
                for(int j=i+1;j<=i+nums[i];j++){
                    if(dp[j]>-1){
                        mini = min(mini,dp[j]);
                    }
                }
                if(mini<nums.size()){
                    dp[i]=mini+1;
                }
            }
        }
        return dp[0];
    }
};
