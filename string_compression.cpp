class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0;
        int n = chars.size();
        if(n==1) return 1;
        
        while(i<n){
            int cnt=1;
            while(i<n-1&&chars[i]==chars[i+1]){
                i++;
                cnt++;
            }
            chars[j++]=chars[i++];
            if(cnt>1){
                string s = to_string(cnt);
                for(int k=0;k<s.size();k++){
                    chars[j++]=s[k];
                }
                cnt=1;
            }
        }
        return j;
    }
};
