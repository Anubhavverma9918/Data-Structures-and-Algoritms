//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    //Just print the space seperated array elements
	void printArray(int arr[], int n) {
	    // code here
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i];
            if (i < n - 1) {
                std::cout << " ";
            }
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.printArray(arr, n);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends