class Solution {
public:
    int f(int val){
        while(val>=10){
            val=val/10;
        }
        return val;
    }
    int compress(vector<char>& chars) {
        // sort(chars.begin(),chars.end());
        string s="";
        s+=chars[0];
        int cnt=1;
        // char curr,prev;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1])
                cnt++;
            else{
                if(cnt==1){
                    s = s+chars[i];
                }
                else{
                    s = s+ to_string(cnt);
                    cnt=1;
                    s+=chars[i];
                }
            }
        }
        if(cnt>1){
            s= s + to_string(cnt);
        }
        vector<char> t;
        for(int i=0;i<s.size();i++){
            t.push_back(s[i]);
        }
        chars = t;

        return chars.size();
    }
};
