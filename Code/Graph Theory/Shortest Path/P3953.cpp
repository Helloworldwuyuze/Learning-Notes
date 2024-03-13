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

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

vector<PII> g[N],r[N];
int t,n,m,k,MOD,x,y,z;
int dis[N],vis[N],f[N][60];
bool flag=false, v[N][60];

void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(mk(0,s)); dis[s]=0;
	while(q.size()){
		int x=q.top().se; q.pop();
		if(vis[x])	continue;
		vis[x]=true;
		for(PII y:g[x])
			if(dis[y.fi]>dis[x]+y.se){
				dis[y.fi]=dis[x]+y.se;
				q.push(mk(dis[y.fi],y.fi));
			}
	}
}

int dfs(int x,int k){
	if(k<0)	return 0;
	if(v[x][k]){ flag=true; return 0;}
	if(f[x][k])	return f[x][k];
	v[x][k]=true;
	int res=0;
	for(PII y:r[x]){
		res=(res+dfs(y.fi,dis[x]-dis[y.fi]+k-y.se))%MOD;
		if(flag)	return 0;
	}
	v[x][k]=false;
	return f[x][k]=res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>MOD;
		flag=false;
		for(int i=1;i<=n;++i)	g[i].clear(), r[i].clear();
		for(int i=1;i<=m;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), r[y].pb(mk(x,z));
		dijkstra(1);
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		dfs(1,0);
		f[1][0]=1;
		int ans=0;
		for(int i=0;i<=k;++i)	ans=(ans+dfs(n,i))%MOD;
		if(flag)	cout<<-1<<endl;
		else	cout<<ans<<endl;
	}
	return 0;
}