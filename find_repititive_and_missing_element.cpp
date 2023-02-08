//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int ans[2];
    int *findTwoElement(int *arr, int n) {
        // code here
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            cnt1+=(i+1);
            cnt2+=arr[i];
        }
        cnt1 = cnt1 - cnt2;
        
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1] > 0){
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            }
            else{
                cnt2 = abs(arr[i]);
                break;
            }
        }
        ans[0]=cnt2;
        ans[1]=cnt2+cnt1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
