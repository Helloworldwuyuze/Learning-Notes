#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;
using LL = modint998244353;
using T = pair<LL, LL>;

LL Pu(LL x, LL y) { return x + y; }
LL E() { return 0; }
LL Pt(T t, LL x) { return x * t.first + t.second; }
T Pa(T x, T y) { return T(x.first * y.first, x.first * y.second + x.second); }
T Id() { return T(1, 0); }

int n, q;
vector<LL> a;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 0, v; i < n; ++i) {
    cin >> v;
    a.push_back(v);
  }
  lazy_segtree<LL, Pu, E, T, Pt, Pa, Id> t(a);
  for (int l, r, x; q--; ) {
    cin >> l >> r >> x;
    LL le = r - l + 1;
    t.apply(l - 1, r, T((le - 1) / le, x / le));
  }
  for (int i = 0; i < n; ++i) {
    cout << t.get(i).val() << ' ';
  }
  return 0;
}
