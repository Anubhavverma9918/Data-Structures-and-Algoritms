//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        stack<string> st;
        int n = S.length();
        string words = "";
      for (int i = 0; i < n; i++)
      {
            
            if(S[i] != '.' && i < n)
            {
                  words += S[i];
            }
            else{
                 st.push(words);
                 words="";
            }
           
      }
           st.push(words);
     S="";
      while (!st.empty())
      {
            S+=st.top();
            S+=".";
            st.pop();
      }
      S.erase(S.end() - 1); // use for erase last index of string
      return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends