#include <iostream>
#include <vector>
using namespace std;
const int N = 1005;
int n, q, a[N];
vector<int> G[N];
void add(int u, int v) { G[u].push_back(v); }
void addedge(int u, int v) { add(u, v), add(v, u); }
int dfs(int u, int fa, int k) {
    if (!k)
        return a[u];
    int ret = 0;
    for (int v : G[u])
        if (v != fa)
            ret += dfs(v, u, k - 1);
    return ret;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i <= n - 1; i++)
        cin >> u >> v, addedge(u, v);
    for (int i = 1, u, k; i <= q; i++) {
        cin >> u >> k;
        cout << dfs(u, 0, k) << '\n';
    }
}