class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m =grid[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ival = i + x[k];
            int jval = j + y[k];
            if(ival>=0 && ival<n && jval>=0 && jval<m && grid[ival][jval]==0 && vis[ival][jval]==0){
                dfs(ival,jval,grid,vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        //for top and bottom row
        for(int i=0;i<m;i++){
            if(grid[0][i]==0 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }

            if(grid[n-1][i]==0 && vis[n-1][i]==0){
                dfs(n-1,i,grid,vis);
            }
        }
        //for leftmost and rightmost column
        for(int i=0;i<n;i++){
            if(grid[i][0]==0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }

            if(grid[i][m-1]==0 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
