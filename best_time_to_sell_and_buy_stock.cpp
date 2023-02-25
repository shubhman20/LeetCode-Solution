class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int min = 1e9;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min = prices[i];
            else{
                ans = max(ans,prices[i]-min);
            }
        }
        return ans;
    }
};
