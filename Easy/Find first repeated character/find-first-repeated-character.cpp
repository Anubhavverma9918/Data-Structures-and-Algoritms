//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    unordered_map<char, int> mp;
    string v = "";
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
        if(mp[s[i]]>1){
            v.push_back(s[i]);
            return v;
        }
    }
    return "-1";
}