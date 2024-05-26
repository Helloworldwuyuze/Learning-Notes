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

int n, m, q;
vector<int> g[N];
int c[N];
int fa[N], dis[N], root, f[N];
bool vis[N];
vector<int> sub;

void dfs1(int x,int fat){
	sub.pb(x); f[x]=fat; vis[x]=true;
	if(dis[x]>dis[root])	root=x;
	for(int y:g[x]){
		if(y==fat)	continue;
		dis[y]=dis[x]+1;
		dfs1(y,x);
	}
}
int find(int x){ return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)	fa[i]=i;
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i){
		if(vis[i])	continue;
		int x;
		dis[root=0]=-1, dfs1(i,0); x=root;
		for(int j:sub)	dis[j]=0;
		sub.clear();
		dis[root=0]=-1, dfs1(x,0);
		for(int j:sub){
			int fx=find(j), fy=find(i);
			if(fx==fy)	continue;
			fa[fx]=fy;
		}
		c[i]=dis[root];
	}
	
	while(q--){
		int op,x,y;
		cin>>op;
		if(op==1)	cin>>x, cout<<c[find(x)]<<endl;
		else{
			cin>>x>>y;
			int fx=find(x), fy=find(y);
			if(fx==fy)	continue;
			fa[fy]=fx;
			c[fx]=max(max(c[fx],c[fy]),(c[fx]+1)/2+(c[fy]+1)/2+1);
		}
	}
	return 0;
}