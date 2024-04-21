//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    // Code here
		    long reverse = 0;
        long sumCopy = n;
        for(int i = 0; n > 0; i++){
            long digit = n % 10;
            if(digit == 0 && i == 0){
                continue;
            }else{
            reverse = reverse * 10 + digit;
            sumCopy /= 10;
            n /= 10;
            }
        }
        return reverse;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends