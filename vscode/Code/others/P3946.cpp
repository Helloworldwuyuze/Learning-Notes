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
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, s, t, lim, dx;
int h[N], l[N], dis[N];
vector<PII> g[N];
bool vis[N];

void dijkstra(){
	memset(dis, 0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(mk(dis[s], s));
	while(q.size()){
		int p = q.top().se; q.pop();
		if(vis[p])	continue;
		vis[p] = true;
		for(PII y:g[p]){
			if(dis[y.fi]>dis[p]+y.se){
				// cout<<p<<" "<<y.fi<<" "<<l[y.fi]<<" "<<(dis[p]+y.se)*dx+h[y.fi]<<endl;
				if((dis[p]+y.se)*dx+h[y.fi]>l[y.fi]&&y.fi!=t)	continue;
				dis[y.fi] = dis[p] + y.se;
				q.push(mk(dis[y.fi], y.fi));
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s>>t>>lim>>dx;
	for(int i=1;i<=n;++i)	cin>>h[i]>>l[i];
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	dijkstra();
	if(dis[t]<=lim)	cout<<dis[t]<<endl;
	else	cout<<"wtnap wa kotori no oyatsu desu!"<<endl;
	return 0;
}