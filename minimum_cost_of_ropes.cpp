class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans=0;
        //min heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();
            ans+= f+s;
            pq.push(f+s);
        }
        return ans;
        
    }
};
