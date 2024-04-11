//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void help(vector<string> &v, int n, int open, int close, string s){
        if(open == n && close == n){
            v.push_back(s);
            return;
        }
        if(open < n){
            help(v, n, open + 1, close, s+"(");
        }
        if(close < open){
            help(v, n, open, close + 1, s+")");
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> v;
        int open = 0;
        int close = 0;
        help(v, n, open, close, "");
        return v;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends