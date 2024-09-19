//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream ss(str);
        string token;
        stack<string> st;
        while(getline(ss, token, '.')){
            st.push(token);
        }
        string res = "";
        while(!st.empty()){
            res +=  st.top();
            st.pop();
            if(!st.empty()){
                res += '.';
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends