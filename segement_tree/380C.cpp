#include<bits/stdc++.h>
using namespace std;

struct info{
    int open, close, full;
    info(int _open=0, int _close=0, int _full=0){
        open = _open;
        close = _close;
        full = _full;
    }
};

info merge(info left, info right){
    info ans;
    int match = min(left.open, right.close);
    ans.full = left.full + right.full + match;
    ans.open = left.open + right.open - match;
    ans.close = left.close + right.close - match;
    return ans;
}

void build(int ind, int low, int high, string &s, vector<info> &seg){
    if(low == high){
        seg[ind] = info(
            s[low] == '(',
            s[low] == ')',
            0
        );
        return;
    }

    int mid = (low + high) / 2;
    build(2*ind+1, low, mid, s, seg);
    build(2*ind+2, mid+1, high, s, seg);
    seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
}

info query(int ind, int low, int high, int l, int r, vector<info>&seg){
    if(r < low || high < l) return info();
    if(low >= l && high <= r) return seg[ind];
    int mid = (low+high)/2;
    info left = query(2*ind+1, low, mid, l, r, seg);
    info right = query(2*ind+2, mid+1, high, l, r, seg);
    return merge(left, right);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<info> seg(4*n);

    build(0, 0, n-1, s, seg);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        info ans = query(0,0,n-1, l, r, seg);
        cout<< ans.full*2 <<endl;

    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
