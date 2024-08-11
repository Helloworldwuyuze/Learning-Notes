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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,sum;
vector<int> g[N];
int c[N];
int siz[N],f[N];

void dfs1(int x,int fa){
	siz[x]=c[x];
	for(int y:g[x]){
		if(y==fa)	continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		f[x]+=f[y]+siz[y];
	}
}

void dfs2(int x,int fa){
	if(x!=1)	f[x]=f[fa]+(sum-siz[x])-siz[x];
	for(int y:g[x]){
		if(y==fa)	continue;
		dfs2(y,x);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)	cin>>c[i], sum+=c[i];
	dfs1(1,0); dfs2(1,0);
	int minn=INF;
	for(int i=1;i<=n;++i)
		minn=min(minn,f[i]);
	cout<<minn<<endl;
	return 0;
}