//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method*/
void printPat(int n)
{
//Your code hereint a=n;
    int m=n;
     while(n>0){
         for(int i=m;i>0;i--){
             for(int j=n;j>0;j--)
                cout<<i<<" ";
         }
         cout<<"$";
         n--;
     }
}