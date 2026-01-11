#include <iostream>
#include <vector>
using namespace std;

// int lcs(string &x, string &y, int i, int j, vector<vector<int>>&dp) {
//     // Base case
//     if (i == 0 || j == 0)
//         return 0;

//     if(dp[i][j]!= -1){
//             return dp[i][j];
//     }

//     if (x[i - 1] == y[j - 1]) {
//         return dp[i][j] = 1 + lcs(x, y, i - 1, j - 1, dp);
//     }
//     else {
//         return dp[i][j] = max(
//             lcs(x, y, i - 1, j, dp),
//             lcs(x, y, i, j - 1, dp)
//         );
//     }
// }

int main() {
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (x[i - 1] == y[j - 1]) {
       dp[i][j] = 1 + dp[i-1][j-1];
    }
    else {
         dp[i][j] = max(
            dp[i-1][j],
            dp[i][j-1]
        );
    }
        }
    }
    cout << dp[n][m] << endl;
    // cout << lcs(x, y, x.length(), y.length(), dp) << endl;
    return 0;
}
