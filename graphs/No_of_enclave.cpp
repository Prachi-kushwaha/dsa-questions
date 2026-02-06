#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
    public:
    int numberOfEnclaves(vector<vector<int>>& grid){
        queue<pair<int, int>>q;
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m,0));

        // traverse through grid and pick only boudaries element and make it 1 in vis matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( i == 0 || j == 0 || i == n-1 || j == m-1){
                  if(grid[i][j] == 1){
                    vis [i][j] = 1;
                    q.push({i,j});
                  }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traversing all the connected grid through boundaries whose value is equal to 1
            for(int k = 0; k<4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0 && !vis[nrow][ncol] && (grid[nrow][ncol] == 1) ){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        // traversing all the elements in the grid and alogside checking on visited array if grid value is one and vis array value is 0 then increase a count

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }

};

int main(){
     vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution obj1;
    cout<<obj1.numberOfEnclaves(grid)<<endl;
    return 0;
}