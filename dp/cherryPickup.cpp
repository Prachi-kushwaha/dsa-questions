#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int index, int rb1, int rb2,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp){

        int n = grid.size();
        int m = grid[0].size();

        if(rb1 < 0 || rb1 >= m || rb2 < 0 || rb2 >= m)
            return -1e8;

        if(index == n-1){
            if(rb1 == rb2)
                return grid[index][rb1];
            else
                return grid[index][rb1] + grid[index][rb2];
        }

        if(dp[index][rb1][rb2] != -1)
            return dp[index][rb1][rb2];

        int maxi = -1e8;

        for(int j1 = -1; j1 <= 1; j1++){
            for(int j2 = -1; j2 <= 1; j2++){

                int value = 0;

                if(rb1 == rb2)
                    value = grid[index][rb1];
                else
                    value = grid[index][rb1] + grid[index][rb2];

                value += f(index+1, rb1+j1, rb2+j2, grid, dp);

                maxi = max(maxi, value);
            }
        }

        return dp[index][rb1][rb2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        return f(0, 0, m-1, grid, dp);
    }
};

int main() {

    vector<vector<int>> grid = {
        {1,0,0,0,0,0,1},
        {2,0,0,0,0,3,0},
        {2,0,9,0,0,0,0},
        {0,3,0,5,4,0,0},
        {1,0,2,3,0,0,6}
    };

    Solution obj;
    cout << obj.cherryPickup(grid) << endl;

    return 0;
}
