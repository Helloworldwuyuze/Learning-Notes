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
const int N = 5e5 + 10;
const int M = 2e6 + 10;

int n,m,x,y;
vector<PII> g[N];
int dfn[N],low[N],idx;

bool vis[N],flag[M];
int cnt;
vector<int> block[N];

void Tarjan(int x,int fa){
	dfn[x]=low[x]=++idx;
	for(PII y:g[x]){
		if(!dfn[y.fi]){
			Tarjan(y.fi,x), low[x]=min(low[x],low[y.fi]);
			if(low[y.fi]>dfn[x])	flag[y.se]=true;
		}
		else if(y.fi!=fa)	low[x]=min(low[x],dfn[y.fi]);
	}
}
void dfs(int x,int fa){
	block[cnt].pb(x); vis[x]=true;
	for(PII y:g[x])
		if(!vis[y.fi]&&!flag[y.se])	dfs(y.fi,x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x>>y, g[x].pb(mk(y,i)), g[y].pb(mk(x,i));
	for(int i=1;i<=n;++i)
		if(!dfn[i])	Tarjan(i,0);
	// for(int i=1;i<=n;++i){
	// 	cout<<"###"<<i<<"###"<<endl;
	// 	for(PII j:g[i])	cout<<j.fi<<" "<<flag[j.se]<<endl;
	// }
	for(int i=1;i<=n;++i)
		if(!vis[i])	++cnt, dfs(i,0);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i){
		cout<<block[i].size()<<" ";
		for(int j:block[i])	cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}