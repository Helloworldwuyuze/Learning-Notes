#include <cmath>
#include <iostream>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5, P = 19260817;
int n, m, a[N], b[N], lans;
int siz, st[N], ed[N], bl[N];
int val[N], sum[N], add[N], add_[N];
int VAL[N], SUM[N], ADD[N];
void build() {
    siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        bl[i] = (i - 1) / siz + 1;
        val[i] = a[i];
        VAL[i] = b[i];
    }
    for (int i = 1; i <= bl[n]; i++) {
        st[i] = (i - 1) * siz + 1, ed[i] = min(i * siz, n);
        for (int j = st[i]; j <= ed[i]; j++) {
            (sum[i] += val[j]) %= P;
            (SUM[i] += VAL[j]) %= P;
        }
    }
}
void push(int x) {
    for (int i = st[x]; i <= ed[x]; i++)
        (val[i] += (i64)add_[x] * VAL[i] % P) %= P;
    add_[x] = 0;
}
void update(int l, int r, int k) {
    if (bl[l] == bl[r]) {
        for (int i = l; i <= r; i++)
            (val[i] += k) %= P;
        (sum[bl[l]] += (i64)(r - l + 1) * k % P) %= P;
        return;
    }
    for (int i = l; i <= ed[bl[l]]; i++)
        (val[i] += k) %= P;
    for (int i = st[bl[r]]; i <= r; i++)
        (val[i] += k) %= P;
    (sum[bl[l]] += (i64)(ed[bl[l]] - l + 1) * k % P) %= P;
    (sum[bl[r]] += (i64)(r - st[bl[r]] + 1) * k % P) %= P;
    for (int i = bl[l] + 1; i <= bl[r] - 1; i++) {
        (sum[i] += (i64)(ed[i] - st[i] + 1) * k % P) %= P;
        (add[i] += k) %= P;
    }
}
void update_0(int l, int r, int k) {
    push(bl[l]);
    if (bl[l] == bl[r]) {
        for (int i = l; i <= r; i++)
            (VAL[i] += k) %= P;
        (SUM[bl[l]] += (i64)(r - l + 1) * k % P) %= P;
        return;
    }
    push(bl[r]);
    for (int i = l; i <= ed[bl[l]]; i++)
        (VAL[i] += k) %= P;
    for (int i = st[bl[r]]; i <= r; i++)
        (VAL[i] += k) %= P;
    (SUM[bl[l]] += (i64)(ed[bl[l]] - l + 1) * k % P) %= P;
    (SUM[bl[r]] += (i64)(r - st[bl[r]] + 1) * k % P) %= P;
    for (int i = bl[l] + 1; i <= bl[r] - 1; i++) {
        (SUM[i] += (i64)(ed[i] - st[i] + 1) * k % P) %= P;
        (ADD[i] += k) %= P;
    }
}
void update_1(int l, int r) {
    if (bl[l] == bl[r]) {
        for (int i = l; i <= r; i++) {
            (val[i] += VAL[i] + ADD[bl[l]]) %= P;
            (sum[bl[l]] += VAL[i] + ADD[bl[l]]) %= P;
        }
        return;
    }
    for (int i = l; i <= ed[bl[l]]; i++) {
        (val[i] += VAL[i] + ADD[bl[l]]) %= P;
        (sum[bl[l]] += VAL[i] + ADD[bl[l]]) %= P;
    }
    for (int i = st[bl[r]]; i <= r; i++) {
        (val[i] += VAL[i] + ADD[bl[r]]) %= P;
        (sum[bl[r]] += VAL[i] + ADD[bl[r]]) %= P;
    }
    for (int i = bl[l] + 1; i <= bl[r] - 1; i++) {
        (sum[i] += SUM[i]) %= P;
        (add_[i] += 1) %= P;
        (add[i] += ADD[i]) %= P;
    }
}
int query(int l, int r) {
    int ret = 0;
    push(bl[l]);
    if (bl[l] == bl[r]) {
        for (int i = l; i <= r; i++)
            (ret += val[i] + add[bl[l]]) %= P;
        return ret;
    }
    push(bl[r]);
    for (int i = l; i <= ed[bl[l]]; i++)
        (ret += val[i] + add[bl[l]]) %= P;
    for (int i = st[bl[r]]; i <= r; i++)
        (ret += val[i] + add[bl[r]]) %= P;
    for (int i = bl[l] + 1; i <= bl[r] - 1; i++)
        (ret += sum[i]) %= P;
    return ret;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    for (int i = 1, op, l, r, k; i <= m; i++) {
        cin >> op >> l >> r;
        l ^= lans, r ^= lans;
        if (op == 1)
            cout << (lans = query(l, r)) << '\n';
        else if (op == 2) {
            cin >> k;
            k ^= lans;
            update(l, r, k);
        } else if (op == 3) {
            cin >> k;
            k ^= lans;
            update_0(l, r, k);
        } else
            update_1(l, r);
    }
}