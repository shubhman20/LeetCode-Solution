class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> m1;
        unordered_map<string,int> m2;
        int j=0;
        for(int i=0;i<s.size();i++){
            while(s[i]==' ') i++;
            string temp="";
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(j==pattern.size()||m1[pattern[j]]!=m2[temp]) return false;
            m1[pattern[j]]=j+1;
            m2[temp]=j+1;
            j++;
        }
        if(j!=pattern.size()) return false;
        return true;
    }
};
