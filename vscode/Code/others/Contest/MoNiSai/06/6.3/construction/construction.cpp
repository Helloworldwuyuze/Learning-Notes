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

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 2e14;

int f[N], g[N], n, m, S, T, k, l, ans;
vector<PII> v[N];

priority_queue<PII, vector<PII>, greater<PII> > q;
bool vis[N];

void dijkstra(int dis[], int s){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;++i)	dis[i]=INF;
	dis[s]=0, q.push(mk(0,s));
	while(q.size()){
		int p=q.top().se; q.pop();
		// cout<<p<<endl;
		if(vis[p])	continue;
		vis[p]=true;
		for(PII y:v[p])
			if(y.se+dis[p]<dis[y.fi])	dis[y.fi]=dis[p]+y.se, q.push(mk(dis[y.fi],y.fi));
	}
}

bool cmp(int x,int y){ return x>y;}
signed main(){
	freopen("construction.in","r",stdin);
	freopen("construction.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	cin>>S>>T>>l>>k;
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, v[x].pb(mk(y,z)), v[y].pb(mk(x,z));
	dijkstra(f, S);
	// cout<<"QAQ"<<endl;
	dijkstra(g, T);
	// cout<<"QAQ"<<endl;
	if(f[T]<=k)	return cout<<n*(n-1)/2<<endl, 0;
	sort(f+1,f+1+n), sort(g+1,g+1+n,cmp);
	int i=1, j=1;
	for(;i<=n;++i){
		while(f[i]+g[j]>k-l&&j<=n)	++j;
		ans+=(n-j+1);
	}
	cout<<ans<<endl;
	return 0;
}
