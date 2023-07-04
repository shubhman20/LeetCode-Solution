//TC----->O(n*m) , SC----->O(n*m) + O(n*m) + 2*O(4)
class Solution {
public:
    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};

    int bfs(int n,int m,vector<vector<char>>& maze,vector<int>&entrance){
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        int ans = INT_MAX;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = row + x[i];
                int ny = col + y[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]!='+' && vis[nx][ny]==0){
                    if(nx==0 || ny==0 || nx==n-1 || ny==m-1){
                        ans = min(ans,cnt+1);
                    } 
                    else{
                        q.push({{nx,ny},cnt+1});
                    }
                    vis[nx][ny]=1;
                }
            }
        }
        return ans;

    }


    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int val = bfs(n,m,maze,entrance);
        if(val==INT_MAX) return -1;
        return val;

    }
};
