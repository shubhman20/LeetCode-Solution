class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int maxi=INT_MIN;
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
            if(m.find(fruits[i])!=m.end()){
                m[fruits[i]]=i;
                cnt++;
            }
            else if(m.size()<2){
                m.insert({fruits[i],i});
                cnt++;
            }
            else{
                int a=INT_MIN,b=INT_MAX;
                for(auto &it :m){
                    a = max(a,it.second);
                    b = min(b,it.second);
                }
                maxi = max(maxi,cnt);
                cnt = a - b;
                m.erase(fruits[b]);
                m.insert({fruits[i],i});
                cnt++;
            }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};
