#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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

#define pi acos(-1)
#define eps (1e-8)
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, A, B;
struct node{
	int x, y;
}pnt[N];
int east[N], west[N], cnte, cntw, rk[N], l[N], r[N];
vector<int> g[N];
bool vis[N];

void dfs1(int x){
	vis[x] = true;
	for(int y:g[x])
		if(!vis[y])	dfs1(y);
}
void dfs2(int x,int le){
	l[x] = le;
	for(int y:g[x])
		if(!l[y])	dfs2(y, le);
}
void dfs3(int x,int ri){
	r[x] = ri;
	for(int y:g[x])
		if(!r[y])	dfs3(y, ri);
}

bool cmp(int x,int y){
	return vis[x] == vis[y] ? pnt[x].y > pnt[y].y : vis[x] > vis[y];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>A>>B;
	for(int i=1;i<=n;++i){
		cin>>pnt[i].x>>pnt[i].y;
		if(pnt[i].x == 0)	west[++cntw] = i;
		if(pnt[i].x == A)	east[++cnte] = i;
	}
	for(int i=1;i<=cntw;++i)	cout<<west[i]<<" ";
	cout<<endl;
	for(int i=1;i<=cnte;++i)	cout<<east[i]<<" ";
	cout<<endl;
	for(int i=1,x,y,k;i<=m;++i){
		cin>>x>>y>>k;
		g[x].pb(y);
		if(k == 2)	g[y].pb(x);
	}
	for(int i=1;i<=cntw;++i)
		if(!vis[west[i]])	dfs1(west[i]);
	sort(east+1, east+1+cnte, cmp);
	for(int i=1;i<=cnte;++i)	rk[east[i]] = i;
	int i;
	for(i=1;vis[east[i]];++i)
		if(!l[i])	dfs2(east[i], i);
	for(--i;i;--i)
		if(!r[i])	dfs3(east[i], i);
	for(int i=1;i<=cntw;++i)
		cout<<r[west[i]] - l[west[i]] + 1<<endl;
	return 0;
}

