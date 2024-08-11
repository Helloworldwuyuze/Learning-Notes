#include <bitset>
#include <cmath>
#include <cstring>
#include <immintrin.h>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC target("avx,avx2")
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 1e5 + 5;
int n, m, blk;
i64 ans;
struct avx256_bitset {
    alignas(32) static u64 c[4];
    u64 *a;
    __m256i *b;
    inline void build() {
        a = (u64 *)_aligned_malloc((n >> 3) + 64, 32);
        memset(a, 0, (n >> 3) + 64);
        b = (__m256i *)a;
    }
    inline void set(int x) { a[x >> 6] |= (1ull << (x & 63)); }
    inline bool test(int x) { return a[x >> 6] & (1ull << (x & 63)); }
    inline int and_count(avx256_bitset &rhs) {
        int ret = 0;
        for (int i = 0; (i << 8) < n; i++) {
            __m256i tmp = _mm256_and_si256(b[i], rhs.b[i]);
            _mm256_store_si256((__m256i *)c, tmp);
            for (int j = 0; j < 4; j++)
                ret += __builtin_popcountll(c[j]);
        }
        return ret;
    }
    inline int or_count(avx256_bitset &rhs) {
        int ret = 0;
        for (int i = 0; (i << 8) < n; i++) {
            __m256i tmp = _mm256_or_si256(b[i], rhs.b[i]);
            _mm256_store_si256((__m256i *)c, tmp);
            for (int j = 0; j < 4; j++)
                ret += __builtin_popcountll(c[j]);
        }
        return ret;
    }
};
alignas(32) u64 avx256_bitset::c[];
struct ds {
    int siz;
    vector<int> v;
    avx256_bitset b;
    inline void rebuild() {
        b.build();
        for (int i : v)
            b.set(i);
        v.clear();
    }
    inline void insert(int x) {
        ++siz;
        if (siz <= blk) {
            v.insert(lower_bound(v.begin(), v.end(), x), x);
            if (siz == blk)
                rebuild();
        } else
            b.set(x);
    }
    inline pair<int, int> query(ds &rhs) {
        if (siz < blk && rhs.siz < blk) {
            int r0 = 0, r1 = n - rhs.siz;
            int j = 0;
            for (int i : v) {
                while (j < rhs.siz && rhs.v[j] < i)
                    ++j;
                if (j < rhs.siz && rhs.v[j] == i)
                    ++r0;
                else
                    --r1;
            }
            return {r0, r1};
        }
        if (siz < blk && rhs.siz >= blk) {
            int r0 = 0, r1 = n - rhs.siz;
            for (int i : v)
                if (rhs.b.test(i))
                    ++r0;
                else
                    --r1;
            return {r0, r1};
        }
        if (siz >= blk && rhs.siz >= blk) {
            int r0 = b.and_count(rhs.b), r1 = n - b.or_count(rhs.b);
            return {r0, r1};
        }
        return rhs.query(*this);
    }
} t[N];
int main() {
    freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    blk = sqrt(n);
    ans = (i64)n * (n - 1) * (n - 2) / 6;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        t[u].insert(v);
        t[v].insert(u);
        int r0, r1;
        tie(r0, r1) = t[u].query(t[v]);
        ans += r0 - r1;
    }
    cout << ans;
}