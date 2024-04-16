//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool valid(vector<vector<int>>& mat, int i, int j, int c){
        for(int k=0; k<9; k++){
            if(mat[i][k] == c){
                return false;
            }
            if(mat[k][j] == c){
                return false;
            }
            if(mat[3*(i/3) + k/3][3*(j/3) + k%3] == c){
                return false;
            }
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j] != 0){
                    int val = mat[i][j];
                    mat[i][j] = 0;
                    if(valid(mat, i, j, val)){
                        mat[i][j] = val;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends