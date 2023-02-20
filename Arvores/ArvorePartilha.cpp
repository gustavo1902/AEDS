#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m;
int a[N];

struct node {
    int l, r, sum;
}tr[N * 4];

void pushup(int p) {
    tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}

void build(int p, int l, int r) {
    tr[p].l = l, tr[p].r = r;
    if(l == r) {
        tr[p].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void modify(int p, int x, int k) {
    if(tr[p].l == tr[p].r) {
        tr[p].sum = k;
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(x <= mid) modify(p << 1, x, k);
    else modify(p << 1 | 1, x, k);
    pushup(p);
}

int query(int p, int l, int r) {
    if(tr[p].l >= l && tr[p].r <= r) return tr[p].sum;
    int mid = (tr[p].l + tr[p].r) >> 1;
    int sum = 0;
    if(l <= mid) sum += query(p << 1, l, r);
    if(r > mid) sum += query(p << 1 | 1, l, r);
    return sum;
}

int main() {
    cin >> n >> m;
    build(1, 1, n);
    while(m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            modify(1, x, 0);
            a[x] = y;
        }
        else cout << query(1, x, y) << endl;
    }
    return 0;
}
