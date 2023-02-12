class Solution {
public:
long long ans=0;
    long long dfs(vector<vector<int>>&adj,vector<int>&vis,int node,int seats){
        vis[node]=1;
        long long cnt=1;
        for(auto &it : adj[node]){
            if(vis[it]!=1){
                cnt+=dfs(adj,vis,it,seats);
            }
        }
        long long val = cnt/seats;
        if(cnt%seats) val++;
        if(node!=0) ans+=val;
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if(roads.size()==0) return 0;
        vector<vector<int>> adj(roads.size()+1);
        int n = roads.size();
        for(int i=0;i<n;i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> vis(n+1,0);
        dfs(adj,vis,0,seats);
        return ans;

    }
};
