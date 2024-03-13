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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,x,y;
vector<int> g[N];
bool vis[N],ins[N];
int dfn[N],low[N],idx,top,st[N];

int cnt,belong[N];
set<int> sc[N];

void Tarjan(int x,int fa){
	dfn[x]=++idx, low[x]=dfn[x];
	st[++top]=x; ins[x]=true;
	for(int y:g[x])
		if(!dfn[y])	Tarjan(y,x), low[x]=min(low[x],low[y]);
		else if(ins[y])	low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x]){
		++cnt;
		do{
			y=st[top--]; belong[y]=cnt;
			sc[cnt].insert(y); ins[y]=false;
		}while(y!=x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x>>y, g[x].pb(y);
	for(int i=1;i<=n;++i)
		if(!dfn[i])
			Tarjan(i,0);
	cout<<cnt<<endl;
	for(int i=1;i<=n;++i)
		if(!vis[belong[i]]){
			vis[belong[i]]=true;
			for(set<int>::iterator it=sc[belong[i]].begin(); it!=sc[belong[i]].end();++it)
				cout<<*it<<" ";
			cout<<endl;
		}
	return 0;
}