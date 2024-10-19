//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.length();
        int ld = str[n-1] - '0';
        
        if(ld <= 5){
            str[n-1] = '0';
        }
        else{
            str[n-1] = '0';
            int carry = 1;
            for(int i=n-2; i>=0; i--){
                int num = str[i] - '0';
                int sum = num + carry;
                str[i] = '0' + sum%10;
                carry = sum/10;
                if(carry == 0){
                    break;
                }
            }
            if(carry == 1){
                return "1" + str;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends