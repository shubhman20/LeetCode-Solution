class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        queue<int>q;
        q.push(1);
        vector<int> vis(n+1,0);
        vis[0]=1;
        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            for(auto &it:adj[node]){
                int child = it.first;
                ans = min(ans,it.second);
                if(vis[child]!=1){
                    q.push(child);
                }
            }
        }
        return ans;
    }
};
