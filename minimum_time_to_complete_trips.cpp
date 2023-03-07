class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=1e14;
        long long l=0;
        long long h = 1e14;
        while(l<h){
            long long mid = l + (h-l)/2;
            long long val=0;
            for(int i=0;i<time.size();i++){
                val+=(long long)(mid/time[i]);
            }
            if(val>=totalTrips){
                ans=min(ans,mid);
                h=mid;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};
