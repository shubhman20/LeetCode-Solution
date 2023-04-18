class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0,flag=1;
        int n = word1.size();
        int m = word2.size();
        while(i<n&&j<m){
            if(flag==1){
                ans.push_back(word1[i]);
                i++;
                flag=0;
            }
            else{
                ans.push_back(word2[j]);
                j++;
                flag=1;
            }
        }
        while(i<n){
            ans.push_back(word1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;

    }
};
