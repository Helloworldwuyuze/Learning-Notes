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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, dep[N], son[N], mx[N], fa[N], ans[N];
vector<int> g[N], f[N];

void dfs1(int x,int fat){
	fa[x] = fat, dep[x] = dep[fat] + 1, mx[x] = 1;
	for(int y:g[x])
		if(y!=fat){
			dfs1(y, x);
			if(mx[y]>mx[son[x]])	son[x] = y;
		}
	mx[x] = mx[son[x]] + 1;
}
void getans(int x){
	if(son[x])	getans(son[x]), swap(f[x], f[son[x]]), ans[x] = ans[son[x]];
	// cout<<x<<" "<<son[x]<<" "<<ans[son[x]]<<endl;
	f[x].pb(1);
	// for(int y:f[x])	cout<<y<<" ";
	// cout<<endl;
	for(int y:g[x])
		if(y!=fa[x]&&y!=son[x]){
			getans(y);
			for(int i = 0, j = mx[x] - mx[y] - 1; i<mx[y]; ++i, ++j){
				f[x][j] += f[y][i];
				if(f[x][j]>f[x][ans[x]] || f[x][j]==f[x][ans[x]] && j>ans[x])	ans[x] = j;
			}
		}
	if(f[x][mx[x]-1]>=f[x][ans[x]])	ans[x] = mx[x]-1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i = 1, x, y; i<n; ++i)
		cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs1(1, 0); getans(1);
	for(int i=1;i<=n;++i)
		cout<<mx[i] - ans[i] - 1<<endl;
	return 0;
}