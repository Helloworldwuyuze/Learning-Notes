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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

vector<PII> g[N];
int n,m,a[N],x,y,z;
int dis[N],vis[N];

void spfa(int s){
	memset(dis,-0x3f,sizeof(dis));
	queue<int> q;
	q.push(s); dis[s]=0;
	while(q.size()){
		int x=q.front(); q.pop();
		vis[x]=false;
		for(PII y:g[x])
			if(dis[y.fi]<dis[x]+y.se){
				dis[y.fi]=dis[x]+y.se;
				if(!vis[y.fi])	q.push(y.fi), vis[y.fi]=true;
			}
	}
// 	for(int i=1;i<=3*n;++i)	cout<<dis[i]<<" ";
// 	cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=m;++i){
		cin>>x>>y>>z;
		g[x].pb(mk(y,0)), g[x+n].pb(mk(y+n,0)), g[x+n*2].pb(mk(y+2*n,0));
		if(z==2)	g[y].pb(mk(x,0)), g[y+n].pb(mk(x+n,0)), g[y+2*n].pb(mk(x+2*n,0)); 
	}
	for(int i=1;i<=n;++i)	g[i].pb(mk(i+n,-a[i])), g[i+n].pb(mk(i+2*n,a[i]));
	spfa(1);
	int maxx=0;
	// for(int i=2*n+1;i<=3*n;++i)
	// 	maxx=max(maxx,dis[i]);
	cout<<dis[3*n]<<endl;
	return 0;
}