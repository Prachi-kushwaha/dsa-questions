#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    const int INF = 1e9;
   vector<vector<int>> matrix(n, vector<int>(n));


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
             cin>>matrix[i][j];
        }
    }
    vector<vector<int>>copy = matrix;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(copy[i][k] == INF || copy[k][j] == INF)
                    continue;
                copy[i][j] = min(copy[i][j], copy[i][k] + copy[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(copy[i][i] < 0){
            cout << "Negative Cycle Detected\n";
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(copy[i][j] == INF)
                cout << "INF ";
            else
                cout << copy[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}