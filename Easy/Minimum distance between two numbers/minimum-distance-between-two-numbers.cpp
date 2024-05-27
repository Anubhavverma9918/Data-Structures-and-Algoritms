//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int cntx = -1;
        int cnty = -1;
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
        if(a[i] == x){
            cntx = i;
            if(cnty != -1){
                mini = min(mini, i - cnty);
            }
        }
        else if(a[i] == y){
            cnty = i;
            if(cntx != -1){
                mini = min(mini, i - cntx);
            }
        }
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
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
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends