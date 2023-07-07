class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        int n = fronts.size();
        for(int i=0;i<n;i++){
            if(fronts[i]==backs[i]){
                mp[fronts[i]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(mp.find(fronts[i])==mp.end()){
                ans = min(ans,fronts[i]);
                mp[fronts[i]]++;
            }

            if(mp.find(backs[i])==mp.end()){
                ans = min(ans,backs[i]);
                mp[backs[i]]++;
            }
        }


        if(ans==INT_MAX) return 0;
        return ans;
    }
};
