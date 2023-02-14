class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int carry=0;
        while(i>=0&&j>=0){
            int val = (a[i]-'0')^(b[j]-'0')^(carry);
            ans.push_back('0'+val);
            carry = ((a[i]-'0')&(b[j]-'0')||(a[i]-'0')&carry||(b[j]-'0')&carry);
            i--;j--;
        }
        while(i>=0){
            int val = (a[i]-'0')^carry;
            carry = (a[i]-'0')&carry;
            ans.push_back('0'+val);
            i--;
        }
        while(j>=0){
            int val = (b[j]-'0')^carry;
            carry = (b[j]-'0')&carry;
            ans.push_back('0'+val);
            j--;
        }
        if(carry){
            ans.push_back('1');
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
