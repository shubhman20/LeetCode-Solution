//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int mod = (1e9+7);
    long long int nthFibonacci(long long int n){
        // code here
        long long int a=0,b=1;
        if(n<2) return n-1;
        for(int i=2;i<=n;i++){
            long long int val = (a+b)%mod;
            a=b;
            b=val;
        }
        return b%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
