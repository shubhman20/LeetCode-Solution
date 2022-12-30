class Solution {
public:

    void dfs(int node,vector<vector<int>>&graph,vector<int>&temp,vector<vector<int>>&ans,int &cnt){
        temp.push_back(node);
        cnt++;
        if(node==graph.size()-1){
            ans.push_back(temp);
        }
        for(auto it:graph[node]){
            int cnt=0;
            dfs(it,graph,temp,ans,cnt);
            while(cnt--)
                temp.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        for(int i=0;i<graph[0].size();i++){
            vector<int>temp;
            temp.push_back(0);
            int cnt=0;
            dfs(graph[0][i],graph,temp,ans,cnt);
        }
        return ans;
    }
};
