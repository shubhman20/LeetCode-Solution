class Solution {
  public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t,dp);
        return dp[i][j]=1+min(f(i-1,j,s,t,dp),min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp)));
    }
  
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return f(s.size()-1,t.size()-1,s,t,dp);
    }
};
