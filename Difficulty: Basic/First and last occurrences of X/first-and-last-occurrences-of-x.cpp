//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low<= high)
        {
            int mid = (low+high)/2;
            if(arr[mid]==x)
            {
                first = mid;
                high = mid -1;
            }
            else if(arr[mid]<x)
            {
                low = mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0;
        high = n-1;
        int last =-1;
        while(low<= high)
        {
            int mid = (low+high)/2;
            if(arr[mid]==x)
            {
                last = mid;
                low = mid +1;
            }
            else if(arr[mid]<x)
            {
                low = mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(first != -1 && last != -1)
        {
            return {first,last};
        }
        return {first};
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