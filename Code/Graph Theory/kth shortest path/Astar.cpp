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

int n,m,k,s,t;
vector<PII> v[N];

int h[N], g[N];
struct node{
	int x, f;
	bool operator <(const node &other) const{ return f+h[x]<other.f+h[other.x]; }
};
priority_queue<node, vector<node>, greater<node> > q;
int vis[N];
void dijkstra(int s){
	for(int i=1;i<=n;++i)	g[i]=INF, vis[i]=0;
	g[s]=0; q.push(node{g[s],s});
	while(q.size()){
		int x=q.top().x; q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(auto y:v[x])
			if(g[x]+y.se<g[y.fi])	g[y.fi]=g[x]+y.se, q.push(node{y.fi,g[y.fi]});
	}
}
void Astar(int s){
	for(int i=1;i<=n;++i)	vis[i]=0, h[i]=g[i], g[i]=INF;
	q.push(node{s,0});
	while(q.size()){
		node x=q.top(); q.pop();
		++vis[x.x];
		if(vis[x.x]==k&&x.x==t){
			cout<<x.f<<endl;
			return ;
		}
		for(auto y:v[x.x])	q.push(node{y.fi,y.se+x.f});
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, v[x].pb(mk(y,z)), v[y].pb(mk(x,z));
	dijkstra(s);
	Astar(s);
	return 0;
}