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
const int N = 1e3 + 10;
const int M = 1e6;

int n,m,k;
int l,x,y;
vector<PII> g[N];
int dis[N],vis[N];

void dijkstra(int s,int mid){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(mk(0,s)), dis[s]=0;
	while(!q.empty()){
		int x=q.top().se; q.pop();
		if(vis[x])	continue;
		vis[x]=true;
		for(PII y:g[x])
			if(dis[y.fi]>dis[x]+(y.se>mid))	dis[y.fi]=dis[x]+(y.se>mid), q.push(mk(dis[y.fi],y.fi));
	}
}

bool check(int mid){
	dijkstra(1,mid);
	// for(int i=1;i<=n;++i)	cout<<dis[i]<<" ";
	// cout<<endl;
	return dis[n]<=k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)	cin>>x>>y>>l, g[x].pb(mk(y,l)), g[y].pb(mk(x,l));
	int l=0, r=M;
	while(l<r){
		// cout<<l<<" "<<r<<endl;
		int mid=l+r>>1;
		if(check(mid))	r=mid;
		else	l=mid+1;
	}
	if(dis[n]==INF)	cout<<-1<<endl;
	else	cout<<l<<endl;
	return 0;
}