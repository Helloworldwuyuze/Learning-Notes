#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
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

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e4 + 10;
const int M = 1e7 + 10;

int n,m,q[N],ret[N],siz[N],dis[N],maxx[N],sum,root;
vector<PII> g[N];
bool vis[N],tf[M];

void calsiz(int x,int fa){
	siz[x]=1; maxx[x]=0;
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=fa){
			calsiz(y.fi,x);
			siz[x]+=siz[y.fi];
			maxx[x]=max(maxx[x],siz[y.fi]);
		}
	maxx[x]=max(maxx[x],sum-siz[x]);
	if(maxx[x]<maxx[root])	root=x;
}

int dd[N],cnt;
queue<int> tag;

void caldis(int x,int fa){
	if(dis[x]>=M)	return ;
	dd[++cnt]=dis[x];
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=fa)
			dis[y.fi]=dis[x]+y.se, caldis(y.fi,x);
}

void dfz(int x,int fa){
	vis[x]=true;
	tf[0]=true; tag.push(0);
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=fa){
			dis[y.fi]=y.se; cnt=0;
			caldis(y.fi,x);
			for(int i=1;i<=cnt;++i)
				for(int j=1;j<=m;++j)
					if(q[j]>=dd[i]&&q[j]-dd[i]<M)	ret[j]|=tf[q[j]-dd[i]];
			for(int i=1;i<=cnt;++i)
				if(dd[i]<M&&tf[dd[i]]==false)	tf[dd[i]]=true, tag.push(dd[i]);
		}
	while(!tag.empty())	tf[tag.front()]=false, tag.pop();
	for(PII y:g[x]){
		if(!vis[y.fi]&&y.fi!=fa){
			root=0, sum=siz[y.fi], maxx[root]=INF;
			calsiz(y.fi,x), calsiz(root,-1);
			dfz(root,x);
		}
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    for(int i=1;i<=m;++i)	cin>>q[i];
    root=0, maxx[root]=INF, sum=n;
    calsiz(1,-1); calsiz(root,-1);
    dfz(root,-1);
    for(int i=1;i<=m;++i)	cout<<(ret[i]?"AYE":"NAY")<<endl;
    return 0;
}
