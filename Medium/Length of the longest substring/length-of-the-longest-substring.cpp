//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int i=0,j=0;
        int n=S.length();
        int ans=1;
     
        vector<int>mp(26,0);
        while(i<n){
            if(mp[S[i]-'a']==0){ mp[S[i]-'a']++;
                i++;
            }
            else{
                ans=max(ans,i-j);
                while(mp[S[i]-'a']>0 && j<i){
                   mp[S[j]-'a']--;
                   j++;
                }
               mp[S[i]-'a']++;
               i++;
            }
        }
        
        ans=max(ans,i-j);
        if(n<ans) return n;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends