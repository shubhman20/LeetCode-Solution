class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>idx;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<queries.size();i++){
            int val = queries[i];
            int temp = upper_bound(nums.begin(),nums.end(),val)-nums.begin();
            idx.push_back(temp);
        }
        return idx;
    }
};
