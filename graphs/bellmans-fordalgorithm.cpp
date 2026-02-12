#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    vector<int> dist(n, 1e8);
    int src;
    cin>>src;
    dist[src] = 0;
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        edges.push_back({u,v,wt});
    }

    for(int i =0; i<n-1; i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            cout << "Negative Weight Cycle Detected\n";
            return 0;
        }

    }

    for(int i = 0; i < n; i++){
        cout << "Distance from " << src << " to " << i << " is "
             << dist[i] << endl;
    }
  return 0;
}