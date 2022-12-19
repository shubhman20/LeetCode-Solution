class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        
        vector<int> vis[n];
        for(int i=0; i<edges.size(); i++){
            vis[edges[i][0]].push_back(edges[i][1]);
            vis[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> v(n,false);
        queue<int> q;
        q.push(source);
        v[source] = true; 
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == destination){
                return true;
            }
            for(auto it : vis[front]){
                if(v[it] == false){
                    v[it] = true;
                    q.push(it);
                    if(it == destination){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
