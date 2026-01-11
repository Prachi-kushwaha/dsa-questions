#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));

    // Input grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }

    // First row
    for (int j = 1; j < m; j++) {
        grid[0][j] += grid[0][j - 1];
    }

    // First column
    for (int i = 1; i < n; i++) {
        grid[i][0] += grid[i - 1][0];
    }

    // Remaining cells
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    cout << grid[n - 1][m - 1] << endl;

    return 0;
}
