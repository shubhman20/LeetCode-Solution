class Solution {
public:
    int partitionString(string s) {
        if(s.length()==1) return 1;
        int cnt=1;
        unordered_map<char,int>mp;
        for(auto &it:s){
            if(mp.find(it)==mp.end()){
                mp.insert({it,1});
            }
            else{
                mp.clear();
                cnt++;
                mp.insert({it,1});
            }
        }
        return cnt;
    }
};
