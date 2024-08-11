#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

using int_t = uint64_t;
const int BIT = sizeof(int_t) * 8;
const int LG = std::__lg(BIT);
const int state = (1 << LG) - 1;

int_t buffer[1 << 25], *ed = buffer + sizeof(buffer) / sizeof(int_t);
inline int_t* alloc(int size) {
	return ed -= size;
}

inline int ctz(uint32_t x) {
	return __builtin_ctz(x);
}
inline int ctz(uint64_t x) {
	return __builtin_ctzll(x);
}
inline int clz(uint32_t x) {
	return __builtin_clz(x);
}
inline int clz(uint64_t x) {
	return __builtin_clzll(x);
}

class bitwise_trie {
		int_t * tree[10];
		int d;
	public :
		bitwise_trie(int size) {
			d = 1;
			for (;; ++d) {
				int cnt = (size + (1 << LG * d) - 1) >> LG * d;
				tree[d - 1] = alloc(cnt);
				if (cnt == 1) break;
			}
		}
		inline void ins(int x) {
			for (int i = 0; i < d; ++i) {
				const int_t w = (int_t) 1 << (x >> i * LG & state);
				if (tree[i][x >> (i + 1) * LG] & w) return ;
				tree[i][x >> (i + 1) * LG] |= w;
			}
		}
		inline void del(int x) {
			for (int i = 0; i < d; ++i)
				if (tree[i][x >> (i + 1) * LG] &= ~((int_t) 1 << (x >> i * LG & state)))
					return ;
		}
		inline int succ(int x) const {
			for (int i = 0; i < d; ++i) {
				const int w = (x >> i * LG) & state;
				const int_t v = tree[i][x >> (i + 1) * LG];
				if ((v >> w) > 1) {
					int ans = x >> (i + 1) * LG << (i + 1) * LG;
					ans += (ctz(v >> (w + 1)) + w + 1) << i * LG;
					for (int j = i - 1; j >= 0; --j)
						ans += ctz(tree[j][ans >> (j + 1) * LG]) << j * LG;
					return ans;
				}
			}
			return 0;
		}
		inline int prev(int x) const {
			for (int i = 0; i < d; ++i) {
				const int w = (x >> i * LG) & state;
				const int_t v = tree[i][x >> (i + 1) * LG];
				if (v & (((int_t) 1 << w) - 1)) {
					int ans = x >> (i + 1) * LG << (i + 1) * LG;
					ans += (state - clz(v & (((int_t) 1 << w) - 1))) << i * LG;
					for (int j = i - 1; j >= 0; --j)
						ans += (state - clz(tree[j][ans >> (j + 1) * LG])) << j * LG;
					return ans;
				}
			}
			return 0;
		}
};

bitwise_trie a(1<<24);
int n, m, t[N], nn, res = 0, rk[N], ans[N];
struct node{
	int l, r, id;
	bool operator <(const node &other) const{ return l/nn == other.l/nn ? (l/nn%2) ? r>other.r : r<other.r : l/nn < other.l/nn; }
}rng[N];

void add(int x){
	int pre = a.prev(t[x]), suf = a.succ(t[x]);
	if(pre)	res += abs(rk[pre] - x);
	if(suf)	res += abs(rk[suf] - x);
	if(pre && suf)	res -= abs(rk[pre] - rk[suf]);
	a.ins(t[x]);
}
void del(int x){
	a.del(t[x]);
	int pre = a.prev(t[x]), suf = a.succ(t[x]);
	if(pre)	res -= abs(rk[pre] - x);
	if(suf)	res -= abs(rk[suf] - x);
	if(pre && suf)	res += abs(rk[pre] - rk[suf]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = sqrt(n);
	for(int i=1;i<=n;++i)	cin>>t[i], rk[t[i]] = i;
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, rng[i] = node{ x, y, i};
	sort(rng+1, rng+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<rng[i].r)	add(++r);
		while(l>rng[i].l)	add(--l);
		while(r>rng[i].r)	del(r--);
		while(l<rng[i].l)	del(l++);
		// cout<<l<<" "<<r<<" "<<res<<endl;.

		ans[rng[i].id] = res;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}