class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c=r;
        vector<vector<int>> dist(r,vector<int>(c,r+c+1));
        int maxi_dist = r+c+1;
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    cnt++;
                }
                else{
                    int r1 = maxi_dist;
                    int c1 = maxi_dist;
                    if(i>0) r1 = dist[i-1][j]+1;
                    if(j>0) c1 = dist[i][j-1]+1;
                    dist[i][j] = min(dist[i][j],min(r1,c1));
                }
            }
        }
        if(cnt==r*c) return -1;
        int ans = INT_MIN;
        for(int i = r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                // if(grid[i][j]==1) continue;
                    int r1=maxi_dist,c1=maxi_dist;
                    if(i<r-1){
                        r1=dist[i+1][j]+1;
                    }
                    if(j<c-1){
                        c1=dist[i][j+1]+1;
                    }
                    dist[i][j]=min(dist[i][j],min(r1,c1));
                ans = max(ans,dist[i][j]);
            }
        }
        if(ans==maxi_dist) return -1;
        else if(ans==0) return 1;
        return ans;
    }
};
