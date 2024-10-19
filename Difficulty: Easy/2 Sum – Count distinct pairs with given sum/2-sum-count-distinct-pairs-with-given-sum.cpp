//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countDistinctPairs(vector<int> &arr, int target) {
        // Code here
        unordered_set<int> seen;
        unordered_set<int> usedPairs;
        int count = 0;
    
        for (int num : arr) {
            int complement = target - num;
            
            if (seen.find(complement) != seen.end() && usedPairs.find(complement) == usedPairs.end()) {
                count++;
                usedPairs.insert(num);
                usedPairs.insert(complement);
            }
            seen.insert(num);
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;

        int res = ob.countDistinctPairs(arr, target);

        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends