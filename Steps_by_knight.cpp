class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool isValid(int x,int y,vector<vector<bool>>&vis){
        if(x<vis.size()&&y<vis[0].size()&&vis[x][y]==false) return true;
        
        return false;
    }
     
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int xt = TargetPos[0]-1,yt = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1,y1=KnightPos[1]-1;
	    if(x1==xt && y1==yt) return 0;
	    queue<pair<int,int>> q;
	    vector<vector<bool>> vis(N,vector<bool>(N,false));
	    int ans=0;
	    q.push({x1,y1});
	    while(!q.empty()){
	        int n = q.size();
	        ans++;
	        int a[8] = {1,1,-1,-1,2,-2,2,-2};
	        int b[8] = {2,-2,2,-2,1,1,-1,-1};
	        while(n--){
	            pair<int,int> p = q.front();
	            q.pop();
	            int x = p.first;int y = p.second;
	            for(int i=0;i<8;i++){
	                int xx = x + a[i];
	                int yy = y + b[i];
	                if(xx==xt&&yy==yt) return ans;
	                if(isValid(xx,yy,vis)){
	                    q.push({xx,yy});
	                    vis[xx][yy]=true;
	                }
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};
