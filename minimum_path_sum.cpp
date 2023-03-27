class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            vector<int> temp(grid[0].size());
            for(int j=0;j<grid[0].size();j++){
                if(i==0&&j==0){
                    temp[0]=grid[0][0];
                    continue;
                }
                int up = 1e9;
                int left = 1e9;
                if(i>0) up = grid[i][j]+dp[j];
                if(j>0) left = grid[i][j]+temp[j-1];
                temp[j]=min(up,left);
            }
            dp=temp;
        }
        return dp[grid[0].size()-1];
    }
};
