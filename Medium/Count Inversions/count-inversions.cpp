//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long left, long long mid, long long right)
      {
        vector<long long>temp;
        long long l = left;
        long long r = mid+1;
        long long int count =0;
        
        while( l<=mid && r <=right){
            if( arr[l] <= arr[r]){
                temp.push_back(arr[l]);
                l++;
            }else{
                temp.push_back(arr[r]);
                // this is a slight change while doing the merging 
                // if the element from the left subarray is smaller than element in right subarray
                // then hust add mid - left +1 to the count 
                count += mid - l +1;
                r++;
            }
        }
        
        while( l <=mid){
            temp.push_back(arr[l]);
            l++;
        }
        
        while( r <= right){
            temp.push_back(arr[r]);
            r++;
        }
        
        for(int i=left;i<=right;i++){
            arr[i] = temp[i-left];
        }
        
        return count;
    }
    
      long long int mergeSort(long long arr[], long long left, long long right){
        long long mid = left + (right -left)/2;
        long long int cnt =0;
        if( left >= right) return cnt;
        cnt+= mergeSort(arr, left, mid);
        cnt+= mergeSort(arr, mid+1, right);
        cnt+= merge( arr, left, mid, right);
        // do the normal sorting using merge sort and merge everytime
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long l= 0 ,r=N-1;
        long long int count = mergeSort(arr , l,r);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends