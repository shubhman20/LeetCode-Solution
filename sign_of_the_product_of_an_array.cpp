class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int x=1;
        for(int i=0;i<nums.size();i++){
            x= x*nums[i];
            if(x>0)
                x = 1;
            else if(x<0)
                x = -1;
            else
                x=0;
            
        }
        
        return x;
    }
};
