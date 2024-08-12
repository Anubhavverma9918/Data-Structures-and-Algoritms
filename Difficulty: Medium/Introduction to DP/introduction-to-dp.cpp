//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int M=1e9+7;
    long long int top(int n, vector<long long int>& dp) {
        // code here
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = (top(n-1, dp) + top(n-2, dp))%M;
    }
    long long int topDown(int n){
        vector<long long int> dp(n+1, -1);
        return dp[n] = top(n, dp);
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1){
            return n;
        }
        int prev = 1;
        int prev1 = 0;
        
        for(int i=2; i<=n; i++){
            int curri=(prev+prev1)%M;
            prev1=prev;
            prev=curri;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends