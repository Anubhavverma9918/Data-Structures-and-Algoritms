//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        set<int> unionSet;

        // Insert all elements of both arrays into the set
        for (int element : a) {
            unionSet.insert(element);
        }
        for (int element : b) {
            unionSet.insert(element);
        }
    
        // Convert set to sorted vector
        vector<int> result(unionSet.begin(), unionSet.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        if (ans.size() == 0) {
            cout << "[]" << endl;
            continue;
        }
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends