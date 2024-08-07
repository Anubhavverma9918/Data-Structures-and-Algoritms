//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool searchNext(vector<vector<char>> &board, string word, int row, int col, 
    int index, int m, int n){
        if(index == word.length()){
            return true;
        }
        if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] or board[row][col] == '!'){
            return false;
        }
        char c = board[row][col];
        board[row][col] = '!';
        
        bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
        
        bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
        
        bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
        
        bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

        board[row][col] = c;

        return top || right || bottom || left;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m = board.size();
        int n = board[0].size();

        int index = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[index]) {
                    if (searchNext(board, word, i, j, index, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends