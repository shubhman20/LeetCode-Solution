class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0,curr=0;
        for(int i=0;i<n;i++){
            pq.push(v[i].second);
            curr+=v[i].second;
            if(pq.size()>k){
                int val = pq.top();
                pq.pop();
                curr-=val;
            }
            if(pq.size()==k) ans = max(ans,curr*v[i].first);
        }
        return ans;

    }
};
