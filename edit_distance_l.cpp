class Solution {
public:
    int EditDistance(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = EditDistance(s,t,i-1,j-1,dp);
        return dp[i][j]=1 + min(EditDistance(s,t,i-1,j-1,dp),min(EditDistance(s,t,i-1,j,dp),EditDistance(s,t,i,j-1,dp)));
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return EditDistance(word1,word2,word1.size()-1,word2.size()-1,dp);

        // return cnt;
    }
};
