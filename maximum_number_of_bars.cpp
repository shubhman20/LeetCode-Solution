class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(),costs.end());
        // int i=0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]&&coins>0){
                ans++;
                coins -=costs[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};
