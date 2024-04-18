//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<string> yShapedPattern(int N) {
        // code here
        vector<string> result;
        string pat = "";
        for(int i=0; i<N; i++) {
            pat = "";
            if(i<N/2)
                pat += string(i, ' ') + "*" + string(N-1-i*2 , ' ') + "*" + string(i, ' ');
            else
                pat += string(N/2, ' ') + "*" + string(N/2, ' ');
            result.push_back(pat);
        }
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.yShapedPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends