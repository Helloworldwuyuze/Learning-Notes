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
const int N = 3e4 + 10;
const int M = 5e5 + 10;
const int K = 1e3;

int n, q, a[N], t, siz[N], mx[N], dep[N], son[N];
vector<int> g[N];
int f[N][K], ans[M], fa[N];

void init(int x,int fat){
	fa[x] = fat;
	siz[x] = 1, dep[x] = dep[fat] + 1, mx[x] = 1;
	for(int y:g[x]){
		if(y==fat)	continue;
		init(y, x);
		siz[x] += siz[y];
		if(mx[son[x]]<mx[y])	son[x] = y;
	}
	mx[x] = mx[son[x]] + 1;
}

void solve(int x){
	f[x][0] = a[x];
	for(int y:g[x]){
		if(y==fa[x])	continue;
		solve(y);
		for(int i=0;i<mx[y]&&i<=999;++i)
			f[x][i+1] += f[y][i];
	}
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	init(1, 0), solve(1);
	for(int i=1;i<=q;++i){
		int x, k; cin>>x>>k;
		if(k==0){ ans[i] = a[x]; continue;}
		ans[i] = f[x][k];
		int fat = fa[x], lst = x;
		while(dep[x]-dep[fat]<k&&fat)	ans[i] += f[fat][k-(dep[x]-dep[fat])] - f[lst][k-(dep[x]-dep[fat])-1], lst = fat, fat = fa[fat];
		ans[i] += f[fat][0];
	}
	if(q<=10000)
		for(int i=1;i<=q;++i)	cout<<ans[i]<<endl;
	else{
		int res = 0;
		for(int i=1;i<=q;++i)	res = res^(i*ans[i]);
		cout<<res<<endl;
	}
	return 0;
}
/*
5 15
1 2 3 4 5
1 2
1 3
2 4
2 5
1 0
1 1
1 2
2 0
2 1
2 2
3 0
3 1
3 2
4 0
4 1
4 2
5 0
5 1
5 2
*/
