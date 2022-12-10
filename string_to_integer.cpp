class Solution {
public:
    void convert(string s,int &num,int idx,int sign){
        if(idx==s.size())
            return;
        else if((s[idx]<'0'||s[idx]>'9')){
            return;
        }
        int temp = s[idx]-'0';
        if(num>INT_MAX/10||(num==INT_MAX/10 && temp>7)){
            if(sign==1)
                num=INT_MAX;
            else
                num=INT_MIN;
            return;
        }
        num= num*10 + temp;
        convert(s,num,idx+1,sign);

    }
    
    int myAtoi(string s) {
        int num=0,idx=0,sign=1;
        while(s[idx]==' '&& idx<s.size()){
            idx++;
        }
        if(s[idx]=='-'){
            sign= -1;
            convert(s,num,idx+1,sign);
        }
        else if(s[idx]=='+'){
            convert(s,num,idx+1,sign);
        }
        else
            convert(s,num,idx,sign);

        if(num==INT_MIN)
            return num;
        
        return num*sign;
    }
};
