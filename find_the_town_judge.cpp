class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>hash(n+1,0);
        vector<int>t(n+1,0);
        for(int i=0;i<trust.size();i++){
            hash[trust[i][1]]++;
            t[trust[i][0]]--;
        }
        int cnt=0,ans=-1;
        for(int i=1;i<=n;i++){
            if(hash[i]==n-1&&t[i]==0){
                ans=i;
            }
        }
        return ans;
    }
};
