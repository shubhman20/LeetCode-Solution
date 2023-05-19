class Solution {
public:
    bool notBipartite(vector<vector<int>>&adj,vector<int>&color,int idx,int curr_color){
        color[idx] = curr_color;
        for(auto &it :adj[idx]){
            if(color[it]==-1){
                if(curr_color==1){
                    if(notBipartite(adj,color,it,0)) return true;
                }
                else{
                    if(notBipartite(adj,color,it,1)) return true;
                }
            }
            else if(curr_color==color[it]) return true;
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(notBipartite(graph,color,i,0))
                    return false;
            }
        }
        return true;
    }
};
