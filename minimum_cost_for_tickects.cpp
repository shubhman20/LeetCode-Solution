class Solution {
public:
    int f(int n,vector<int> &days,vector<int>&costs,vector<int>&dp,int idx){
        if(idx>=n) return 0;
        int one = costs[0] + f(n,days,costs,dp,idx+1);
        if(dp[idx]!=-1) return dp[idx];
        int i;
        for(i=idx;i<n&& days[i]<days[idx]+7;i++);
        int seven = costs[1] + f(n,days,costs,dp,i);
        for(i=idx;i<n&&days[i]<days[idx]+30;i++);
        int thirty = costs[2]+f(n,days,costs,dp,i);
        return dp[idx]=min(one,min(seven,thirty));
    }
    int fTab(int n,vector<int>&days,vector<int>&costs){
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        for(int k=n-1;k>=0;k--){
            int one = costs[0] + dp[k+1];
            int i;
            for(i=k;i<n&& days[i]<days[k]+7;i++);
            int seven = costs[1] + dp[i];
            for(i=k;i<n&&days[i]<days[k]+30;i++);
            int thirty = costs[2]+dp[i];
            dp[k]=min(one,min(seven,thirty));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return f(n,days,costs,dp,0);
    }
};
