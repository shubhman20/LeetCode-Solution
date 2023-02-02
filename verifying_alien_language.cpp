class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.length();
        vector<int> m(26,0);
        for(int i=0;i<n;i++){
            //storing the position
            m[order[i] - 'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            bool flag = false;
            string s1 = words[i];
            string s2 = words[i+1];
            for(int j=0;j<min(s1.length(),s2.length());j++){
                if(m[s1[j]-'a']<m[s2[j]-'a']){
                    flag = true;
                    break;
                }
                if(m[s1[j]-'a']>m[s2[j]-'a'])
                    return false;
            }
            if(!flag && s1.length()>s2.length())
            return false;
        }
        
        return true;
    }
};
