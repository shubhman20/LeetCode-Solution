class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char>a(26);
        for(int i=0;i<26;i++){
            a[i] = 'a' + i;
        }
        char found,replace;
        for(int i=0;i<s1.size();i++){
            found = max(a[s1[i]-'a'],a[s2[i]-'a']);
            replace = min(a[s1[i]-'a'],a[s2[i]-'a']);
            for(int j=0;j<26;j++){
                if(a[j]==found){
                    a[j]=replace;
                }
            }
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i] = a[baseStr[i]-'a'];
        }
        return baseStr;
    }
};
