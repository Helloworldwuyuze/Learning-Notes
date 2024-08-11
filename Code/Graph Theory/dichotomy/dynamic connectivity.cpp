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
const int N = 5e3 + 10;
const int M = 5e5 + 10;

int n, q, m;
struct edge{
	int u, v, l, r;
};
vector<edge> a;
int op[M], x[M], y[M];
map<PII, int> ma;

int f[N], vis[N], cnt;
bool exist[N];
vector<int> g[N];
void insert(int x,vector<int> &key){
	if(!exist[x])	key.pb(x), exist[x] = true;
}
void dfs(int x,int cnt){
	vis[x] = cnt;
	for(int y:g[x])	if(!vis[y])	dfs(y, cnt);
}

void divide(int l,int r,vector<edge> &a){
	// cout<<"enter"<<l<<" "<<r<<endl;
	// cout<<"father! "<<" "<<f[123]<<" "<<f[127]<<endl;
	vector<int> key;
	for(edge e:a)
		insert(e.u, key), insert(e.v, key);
	for(int i=l;i<=r;++i)
		if(op[i] == 2)	insert(x[i], key), insert(y[i], key);
	// for(int x:key)	cout<<"Key!"<<x<<" "<<f[x]<<endl;
	for(int x:key)	vector<int>().swap(g[f[x]]), exist[x] = vis[f[x]] = 0;

	for(edge e:a)
		if(e.l <= l && r <= e.r){
			int x = f[e.u], y = f[e.v];
			// cout<<"edge"<<x<<" "<<y<<endl;
			g[x].pb(y), g[y].pb(x);
		}

	cnt = 0;
	for(int x:key)
		if(!vis[f[x]])	dfs(f[x], ++cnt);
	vector<int> tf;
	tf.resize(key.size());

	for(int i=0;i<key.size();++i)
		tf[i] = f[key[i]], f[key[i]] = vis[f[key[i]]];
	// for(int i=0;i<tf.size();++i)
		// cout<<"tf! "<<f[key[i]]<<" "<<tf[i]<<endl;

	int mid = l+r>>1;
	// cout<<"father! "<<f[123]<<" "<<f[127]<<endl;
	if(l == r){
		if(op[l] == 2)	cout<<(f[x[l]] == f[y[l]] ? 'Y' : 'N')<<endl;
	}
	else{
		vector<edge> tmp;
		for(edge e:a)
			if(!(e.l<=l && r<=e.r) && e.l <= mid)	tmp.pb(e);
		divide(l, mid, tmp);
		vector<edge>().swap(tmp);
		for(edge e:a)
			if(!(e.l<=l && r<=e.r) && e.r > mid)	tmp.pb(e);
		divide(mid+1, r, tmp);
	}

	for(int i=0;i<key.size();++i)
		f[key[i]] = tf[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=q;++i){
		cin>>op[i]>>x[i]>>y[i];
		if(x[i] < y[i])	swap(x[i], y[i]);
		if(op[i] == 0)	ma[mk(x[i], y[i])] = m++, a.pb(edge{x[i], y[i], i, 0});
		else if(op[i] == 1)	a[ma[mk(x[i], y[i])]].r = i;
	}
	for(int i=1;i<=n;++i)	f[i] = i;
	for(edge &e:a)
		if(!e.r)	e.r = q;
	// for(edge e:a)	cout<<e.u<<" "<<e.v<<" "<<e.l<<" "<<e.r<<endl;
	divide(1, q, a);
	return 0;
}