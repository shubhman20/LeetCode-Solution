class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size(),i=0;
        if(k==1){
            if(n==0) return true;
            else if(n==1 && flowerbed[0]==0) return true;
            else{
                return false;
            }
        }
        for(i=0;i<k-1;i++){
            if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                n--;
                flowerbed[i]=1;
            }
            else if(i>0 && flowerbed[i-1]==0 && flowerbed[i]==0 &&flowerbed[i+1]==0){
                n--;flowerbed[i]=1;
            }

            if(n<=0) return true;
        }
        if(i>0 && flowerbed[i-1]==0&&flowerbed[i]==0) n--;

        if(n==0) return true;

        return false;
    }
};
