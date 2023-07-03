 string repeat(string temp,int k){
        string t="";
        while(k--){
            t+=temp;
        }
        return t;
    }


    string decodeString(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                string k ="";
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    k = st.top() + k;
                    st.pop();
                }
                int val=0;
                if(k.size()>0){
                    val = stoi(k);
                }
                string v = repeat(temp,val);
                for(int i=0;i<v.size();i++){
                    st.push(v[i]);
                }
            }
        }

        string ans="";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }

        return ans;
    }
