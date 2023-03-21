class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                long long cnt=1;
                i++;
                while(i<nums.size()&&nums[i]==0){
                    cnt++;
                    i++;
                }
                ans += cnt + cnt*(cnt-1)/2;
            }
        }
        return ans;
    }
};
