#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int arr[N];
int seg[4 * N + 5]; 


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Build segment tree
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = gcd(seg[2 * idx], seg[2 * idx + 1]);
}

// query GCD of range l ql to qr
int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;

    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    return gcd(
        query(2 * idx, l, mid, ql, qr),
        query(2 * idx + 1, mid + 1, r, ql, qr)
    );
}

// point updates the segment tree
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * idx, l, mid, pos, val);
    else update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = gcd(seg[2 * idx], seg[2 * idx + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    build(1, 1, n);

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}
