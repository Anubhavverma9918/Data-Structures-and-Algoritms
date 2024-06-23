//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool countPainters(int arr[], int n, int k, long long times){
        int painters = 1;
        long long boardPainter = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] + boardPainter <= times){
                boardPainter += arr[i];
            }
            else{
                painters++;
                if(arr[i] > times || painters > k){
                    return false;
                }
                boardPainter = arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum 
        long long low = 0;
        long long sum = 0;
        long long ans = -1;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        long long high = sum;
        long long mid = low+(high-low)/2;
        
        while (low <= high) {
            if (countPainters(arr,n,k,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            mid = low+(high-low)/2;
        }
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends