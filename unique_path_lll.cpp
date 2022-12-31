class Solution {
public:
int cnt=0;
    int rec(vector<vector<int>>&grid,int x,int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[x].size()||grid[x][y]==-1)
            return 0;
        if(grid[x][y]==2){
            if(cnt==-1)
                return 1;
            else
                return 0;
        }
        cnt--;
        grid[x][y]=-1;
        int totalpaths = rec(grid,x-1,y)+rec(grid,x,y-1)+rec(grid,x+1,y)+rec(grid,x,y+1);
        grid[x][y]=0;
        cnt++;
        return totalpaths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) cnt++;
                else if(grid[i][j]==1){
                    x=i;y=j;
                }
            }
        }
        return rec(grid,x,y);
    }
};
