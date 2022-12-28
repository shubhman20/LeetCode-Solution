class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k--){
            int val = pq.top();
            pq.pop();
            val = (val+1)/2;
            pq.push(val);
        }
        int ans=0;
        while(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }
        return ans;
    }
};
