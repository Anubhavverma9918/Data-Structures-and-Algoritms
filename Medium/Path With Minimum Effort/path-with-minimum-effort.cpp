//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,-1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        // direction of row and column
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 and col==m-1) return (-1)*diff;
            // 4 directions up, right, down, left
            for(int i{0};i<4;i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 and newc>=0 and newr<n and newc < m)
                {
                    int newEffort = min((-1)*abs(heights[row][col]-heights[newr][newc]), diff);
                    if(newEffort > dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({dist[newr][newc], {newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends