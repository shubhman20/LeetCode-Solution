class Solution {
public:
    int dfs(int s,vector<vector<int>>&adj,vector<bool>&vis,int n,vector<bool>&hasApple){
        int totalTime=0;
        for(auto &it:adj[s]){
            if(vis[it]==false){
                vis[it]=true;
                int childTime = dfs(it,adj,vis,n,hasApple);
                if(childTime!=0||hasApple[it]==true){
                    totalTime+= (childTime+2);
                }
            }
        }
        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,false);
        vis[0]=true;
        return dfs(0,adj,vis,n,hasApple);
    }
};
