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
const int N = 2e5 + 10;
const int M = 1e6;

int n,k,siz[N],maxx[N],dis[N],minn[M],dep[N],ans=INF;
vector<PII> g[N];
int sum,root;
bool vis[N],tf[M];

void calsiz(int x,int fa){
	siz[x]=1, maxx[x]=0;
	for(PII y:g[x])
		if(y.fi!=fa&&!vis[y.fi]){
			calsiz(y.fi,x);
			siz[x]+=siz[y.fi], maxx[x]=max(maxx[x],siz[y.fi]);
		}
	maxx[x]=max(maxx[x],sum-siz[x]);
	if(maxx[x]<maxx[root])	root=x;
}

int dd[N],ddep[N],cnt;
void caldis(int x,int fa){
	if(dis[x]>=M)	return ;
	dd[++cnt]=dis[x]; ddep[cnt]=dep[x];
	for(PII y:g[x])
		if(y.fi!=fa&&!vis[y.fi])
			dep[y.fi]=dep[x]+1, dis[y.fi]=dis[x]+y.se, caldis(y.fi,x);
}
queue<int> tag;

void dfz(int x,int fa){
	vis[x]=true;
	for(PII y:g[x])
		if(y.fi!=fa&&!vis[y.fi]){
			dis[y.fi]=y.se, dep[y.fi]=1; cnt=0;
			caldis(y.fi,x);
			for(int i=1;i<=cnt;++i)
				if(k>=dd[i]&&tf[k-dd[i]])	ans=min(ans,ddep[i]+minn[k-dd[i]]);
			for(int i=1;i<=cnt;++i)
				if(dd[i]<M)	tf[dd[i]]=true, minn[dd[i]]=min(minn[dd[i]],ddep[i]), tag.push(dd[i]);
		}
	while(!tag.empty())	tf[tag.front()]=false, minn[tag.front()]=INF, tag.pop();
	for(PII y:g[x])
		if(y.fi!=fa&&!vis[y.fi]){
			root=0, maxx[root]=INF, sum=siz[y.fi];
			calsiz(y.fi,x), calsiz(root,-1);
			dfz(root,x);
		}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, ++x,++y, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    root=0, maxx[root]=INF, sum=n;
    calsiz(1,-1); calsiz(root,-1); tf[0]=true;
    memset(minn,0x3f,sizeof(minn)); minn[0]=0;
    dfz(root,-1);
    if(ans==INF)	cout<<-1<<endl;
    else	cout<<ans<<endl;
    return 0;
}


