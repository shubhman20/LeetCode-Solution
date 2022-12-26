class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(),false);
        dp[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--){
            int val = nums[i];
            if(val+i+1>=nums.size())
                dp[i]=true;
            else{
                for(int j=1;j<=val;j++){
                    if(dp[j+i]==true){
                        dp[i]=true;break;
                    }
                }
            }
        }
        return dp[0];
        
    }
};
