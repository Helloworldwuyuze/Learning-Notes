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

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e5 + 10;
const int M = 1e6 + 10;

int n,maxx[N][2],root;
vector<int> g[N];
int siz[N],f[N];
bool ans[N];

void FindRoot(int x,int fa){
	siz[x]=1;
	bool flag=true;
	for(int y:g[x]){
		if(y==fa)	continue;
		FindRoot(y,x);
		if(siz[y]>n/2)	flag=false;
		siz[x]+=siz[y];
	}
	if(n-siz[x]>n/2)	flag=false;
	if(flag)	root=x;
}
void PreCal(int x,int fa){
	siz[x]=1;
	for(int y:g[x]){
		if(y==fa)	continue;
		PreCal(y,x);
		siz[x]+=siz[y];
		if(siz[y]>n/2)	continue;
		if(siz[y]>maxx[x][0])	maxx[x][1]=maxx[x][0], maxx[x][0]=siz[y];
		else if(siz[y]>maxx[x][1])	maxx[x][1]=siz[y];
	}
}
void Ans(int x,int fa,int mx){
	f[x]=mx;
	for(int y:g[x]){
		if(y==fa)	continue;
		if(n-siz[x]<=n/2)	mx=max(mx,n-siz[x]);
		if(siz[y]==maxx[x][0])	Ans(y,x,max(mx,maxx[x][1]));
		else	Ans(y,x,max(mx,maxx[x][0]));
	}
	if(n-siz[x]-f[x]<=n/2)	ans[x]=true;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	FindRoot(1,0); PreCal(root,0); Ans(root,0,0);
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
    return 0;
}