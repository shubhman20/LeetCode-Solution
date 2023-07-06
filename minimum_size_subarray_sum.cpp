class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int val=0;
        int ans=INT_MAX;
        while(i<n){
            val+=nums[i];
            if(val>=target){
                ans=min(ans,i-j+1);
                while(j<i && val>=target){
                    val-=nums[j];
                    if(val>=target && j<i){
                        ans = min(ans,i-j);
                    }
                    j++;
                }
                // ans = min(ans,i-j+2);
            }
            i++;
        }
        if(val>=target){
            ans = min(ans,i-j);
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
