//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long>ans,temp;
        int mod=1000000007;
        if(n==1)
        {
            ans.push_back(1);
            return ans;
        }
        ans.push_back(1);
        ans.push_back(1);
        for(int i=2;i<n;i++)
        {
            int s=ans.size();
            temp.clear();
            for(int i=0;i<s;i++)
            {
                if(i==0)
                {
                  temp.push_back(1);  
                }
                else if(i==s-1)
                {
                    long long temp1=ans[i]%mod , temp2 = ans[i-1];
                    temp.push_back((temp1+temp2)%mod);
                    temp.push_back(1);  
                }
                else
                {
                    long long temp1=ans[i]%mod , temp2 = ans[i-1];
                    temp.push_back((temp1+temp2)%mod);
                }
            }
            ans=temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends