//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
        long first = 0;
        long second = 1;
        long sum = 1;
        
        for(int i=2; i<=N; i++){
            long temp = (first+second) % 1000000007;
            sum = sum + temp;
            first = second;
            second = temp;
        }
        
        return sum % 1000000007;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends