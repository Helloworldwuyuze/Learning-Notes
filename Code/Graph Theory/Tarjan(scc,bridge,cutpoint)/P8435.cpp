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
const int M = 1e6 + 10;

int n,m,x,y,z;
vector<int> g[N];
int cnt,dfn[N],low[N],idx;
vector<int> pbcc[N];
stack<int> s;

void Tarjan(int x,int fa){
	dfn[x]=low[x]=++idx;
	int son=0; s.push(x);
	for(int y:g[x]){
		if(y==fa)	continue;
		if(!dfn[y]){
			++son;
			Tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				++cnt;
				do{
					z=s.top(); s.pop(); pbcc[cnt].pb(z);
				}while(z!=y);
				pbcc[cnt].pb(x);
			}
		}else	low[x]=min(low[x],dfn[y]);
	}
	if(son==0&&fa==0)	pbcc[++cnt].pb(x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)
		if(!dfn[i])	Tarjan(i,0);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i){
		cout<<pbcc[i].size()<<" ";
		for(int j:pbcc[i])	cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}