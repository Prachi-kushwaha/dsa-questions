#include<bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int arr[], int seg[]){
    if(low==high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    build(2*ind+1, low, mid, arr, seg);
    build(2*ind+2, mid+1, high, arr, seg);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);

}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int seg[4*n];
    build(0, 0, n-1, arr, seg);
    for(int i = 0; i < 2*n; i++)
    cout << seg[i] << " ";

}

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    #endif
    solve();
    return 0;
}