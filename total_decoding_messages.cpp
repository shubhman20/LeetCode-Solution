class Solution {
	public:
	    long long mod = 1e9 + 7;
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    int cnt=0;
		    if(str.size()==0) return 0;
		    vector<int> dp(n+1,0);
		    dp[0]=1;
		    dp[1]=1;
		    for(int i=2;i<=n;i++){
		        if(str[i-1]>'0'){
		            dp[i]=dp[i-1];
		        }
		        if(str[i-2]=='1'||str[i-2]=='2'&&str[i-1]<'7'){
		          //  dp[i]=dp[i+1];
		            dp[i] = (dp[i]+dp[i-2])%mod;
		        }
		        
		    }
		    return dp[n];
		}

};
