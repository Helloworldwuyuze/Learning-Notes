#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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

#define pi acos(-1)
#define eps (1e-8)
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, q, x, y, p[N], rk[N], fa[N];
char op;

int root[N], ls[N<<5], rs[N<<5], s[N<<5], idx;
void update(int &p,int l,int r,int x,int k){
	if(!p)	p = ++idx;
	if(l == r)	return (void)(s[p] += k);
	int mid = l+r>>1;
	if(x <= mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
	s[p] = s[ls[p]] + s[rs[p]];
}
int kth(int p,int l,int r,int k){
	if(l == r)	return l;
	int mid = l+r>>1;
	if(k <= s[ls[p]])	return kth(ls[p], l, mid, k);
	else	return kth(rs[p], mid+1, r, k - s[ls[p]]);
}
int merge(int p,int q,int l,int r){
	if(!p || !q)	return p+q;
	s[p] += s[q];
	if(l == r)	return p;
	int mid = l+r>>1;
	ls[p] = merge(ls[p], ls[q], l, mid);
	rs[p] = merge(rs[p], rs[q], mid+1, r);
	return p;
}

int find(int x){ return fa[x] == x ? fa[x] : find(fa[x]); }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>p[i], rk[p[i]] = i, update(root[i], 1, n, p[i], 1);
	for(int i=1;i<=n;++i)	fa[i] = i;
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		int fx = find(x), fy = find(y);
		if(fx == fy)	continue;
		fa[fx] = fy;
		root[fy] = merge(root[fy], root[fx], 1, n);
	}
	// for(int i=1;i<=idx;++i)	cout<<i<<" "<<ls[i]<<" "<<rs[i]<<" "<<s[i]<<endl;
	cin>>q;
	while(q--){
		cin>>op>>x>>y;
		if(op == 'B'){
			int fx = find(x), fy = find(y);
			if(fx == fy)	continue;
			fa[fx] = fy;
			root[fy] = merge(root[fy], root[fx], 1, n);
		}else{
			int fx = find(x);
			// cout<<fx<<endl;
			if(s[root[fx]] < y)	cout<<-1<<endl;
			else	cout<<rk[kth(root[fx], 1, n, y)]<<endl;
		}
	}
	return 0;
}