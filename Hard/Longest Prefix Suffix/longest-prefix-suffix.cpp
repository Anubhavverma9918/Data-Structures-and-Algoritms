//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int> lp(s.size(), 0);
	    int i = 1;
	    int j = 0;
	    
	    while(i < s.size()){
	        if(s[i] == s[j]){
	            lp[i] = j + 1;
	            i++;
	            j++;
	        }
	        else{
	            if(j != 0){
	                j = lp[j - 1];
	            }
	            else{
	                i++;
	            }
	        }
	    }
	    return lp.back();
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends