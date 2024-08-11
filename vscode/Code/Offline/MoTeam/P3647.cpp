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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 1e5 + 10;
const int M = 1e5;

int n, m, a[N], nn, col[N];
struct node{
	int op, l, r, x, id;
	inline bool operator <(const node &other) const { return l/nn == other.l/nn ? (l/nn&1) ? r>other.r : r<other.r : l/nn < other.l/nn; }
}rng[N];
bitset<N> f, g;
bool ans[N];

inline void add(int x){
	if(++col[x]==1)	f.flip(x), g.flip(M-x);
}
inline void del(int x){
	if(--col[x]==0)	f.flip(x), g.flip(M-x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = sqrt(n);
	for(int i=1;i<=n;++i)   cin>>a[i];
	for(int i=1;i<=m;++i)   cin>>rng[i].op>>rng[i].l>>rng[i].r>>rng[i].x, rng[i].id = i;
	sort(rng+1, rng+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<rng[i].r)   add(a[++r]);
		while(l>rng[i].l)   add(a[--l]);
		while(r>rng[i].r)   del(a[r--]);
		while(l<rng[i].l)   del(a[l++]);
		if(rng[i].op == 1)	ans[rng[i].id] = (f & (f<<rng[i].x)).any();
		else if(rng[i].op == 2)	ans[rng[i].id] = (f & (g>>(M-rng[i].x))).any();
		else{
			for(int j=1;j*j<=rng[i].x;++j)
				if(rng[i].x%j == 0)	ans[rng[i].id] |= f[j] & f[rng[i].x/j];
		}
	}
	for(int i=1;i<=m;++i)
		if(ans[i])	cout<<"hana"<<endl;
		else	cout<<"bi"<<endl;
	return 0;
}