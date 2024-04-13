//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int ans = -1;
        int res = -1;
        vector<int> v;
        for(int i=0; i<n; i++){
            if(arr[i] == x && ans == -1){
                ans++;
                v.push_back(i);
            }
            if(arr[i] == x){
                res = i;
            }
            
        }
        if(res == -1){
            return {-1};
        }
        v.push_back(res);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends