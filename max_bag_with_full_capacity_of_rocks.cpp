class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> a(rocks.size());
        for(int i=0;i<rocks.size();i++){
            a[i] = capacity[i]-rocks[i];
        }
        sort(a.begin(),a.end());
        int tot=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==0)
                tot++;
            else if(a[i]-additionalRocks<=0)
            {
                tot++;
                additionalRocks-=a[i];
            }
        }
        return tot;
    }
};
