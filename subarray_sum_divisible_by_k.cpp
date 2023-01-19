class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,rem=0;
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(sum<0){
                sum = sum%k + k;
            }
            rem=sum%k;
            mp[rem]++;
            ans += mp[rem]-1;
        }
        return ans;
    }
};
