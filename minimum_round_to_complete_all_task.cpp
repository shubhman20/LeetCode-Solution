class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto &it:m){
            if(it.second==1){
                ans=-1;break;
            }
          
            if(it.second%3==0){
                ans+=(it.second/3);
            }
            else{
                ans+= (it.second/3)+1;
            }
        }
        return ans;
    }
};
