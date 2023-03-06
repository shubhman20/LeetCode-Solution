class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> temp(k+arr[arr.size()-1]+1,1);
        temp[0]=0;
        for(int i=0;i<arr.size();i++){
            temp[arr[i]]=0;
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]==1)  k--;
            if(k==0) return i;
        }
        return 1;
    }
};
