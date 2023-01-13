class Solution {
public:
    void dfs(int currNode,vector<vector<int>>&adj,string &s,int &ans,vector<int>&dist){
        dist[currNode]=1;
        for(int it:adj[currNode]){
            dfs(it,adj,s,ans,dist);
            if(s[currNode]!=s[it]){
                ans=max(ans,dist[currNode]+dist[it]);
                dist[currNode] = max(dist[it]+1,dist[currNode]);
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adj(n+1);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int ans=1;
        vector<int> dist(n+1,0);
        dfs(0,adj,s,ans,dist);
        return ans;
    }
};
