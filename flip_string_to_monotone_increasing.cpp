class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(s.size()==1) return 0;
        int ones=0,zeroes=0,flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ones++;
            }
            else if(ones>0 && s[i]=='0'){
                zeroes++;
            }
            zeroes = min(zeroes,ones);
        }
        return zeroes;
    }
};
