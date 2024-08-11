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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n, a[N], m, blk[N], nn, cnt, b[N], ans[N], ed[N], res, st[N];
struct node{
	int l, r, id;
	bool operator <(const node &other) const{ return blk[l] == blk[other.l] ? r<other.r : blk[l] < blk[other.l]; }
}rng[N];

int calc(node rng){
	int lst[N], ans = 0;
	for(int i=rng.l;i<=rng.r;++i)   lst[a[i]] = 0;
	for(int i=rng.l;i<=rng.r;++i)
		if(lst[a[i]])	ans = max(ans, i - lst[a[i]]);
		else	lst[a[i]] = i;
	return ans;
}

vector<int> g;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; nn = sqrt(n);
	for(int i=1;i<=n;++i)   cin>>a[i], b[i] = a[i];
	sort(b+1, b+1+n);
	cnt = unique(b+1, b+1+n) - b - 1;
	for(int i=1;i<=n;++i)   a[i] = lower_bound(b+1, b+1+cnt, a[i]) - b;
	cin>>m;
	for(int i=1;i<=m;++i)   cin>>rng[i].l>>rng[i].r, rng[i].id = i;
	for(int i=1;i<=n;++i)   blk[i] = (i-1)/nn+1;
	cnt = blk[n];
	sort(rng+1, rng+1+m);
	for(int i=1,j=1; i<=m && j<=cnt; ++j){
		res = 0;
		int right = min(j * nn, n), l = right+1, r = l-1;
		for(; blk[rng[i].l] == j; ++i){
			if(blk[rng[i].r] == j){
				ans[rng[i].id] = calc(rng[i]);
				continue;
			}
			while(r<rng[i].r){
				++r;
				ed[a[r]] = r;
				if(!st[a[r]])	st[a[r]] = r, g.pb(a[r]);
				res = max(res, r - st[a[r]]);
			}
			int tmp = res;
			while(l>rng[i].l){
				--l;
				if(ed[a[l]])	res = max(res, ed[a[l]] - l);
				else	ed[a[l]] = l;
			}
			ans[rng[i].id] = res;
			while(l<=right){
				if(ed[a[l]] == l)	ed[a[l]] = 0;
				++l;
			}
			res = tmp;
		}
		for(int x:g)	st[x] = ed[x] = 0;
		g.clear();
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}