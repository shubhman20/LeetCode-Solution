class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int tot = k+arr[arr.size()-1]+1;
        int i=1,idx=0;
        while(k>0&&idx<arr.size()){
            if(i<arr[idx]){
                k--;
                i++;
            }
            else if(i==arr[idx]){
                i++;idx++;
            }
        }
        return i+k-1;
    }
};
