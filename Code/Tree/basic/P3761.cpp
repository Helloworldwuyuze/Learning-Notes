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

struct edge{
	int u,v,w,nxt;
}e[N];
int head[N], tot=-1;
void add(int x,int y,int z){ e[++tot]=edge{x,y,z,head[x]}, head[x]=tot;}

int n, ans=INF, fa[N], dis[N], tmp, root;
void dfs(int x,int fat,int cn){
	fa[x]=fat;
	if(dis[root]<dis[x])    root=x;
	for(int i=head[x];~i;i=e[i].nxt){
		if(i==cn||(i^1)==cn)    continue;
		int y=e[i].v;
		if(y==fat)  continue;
		dis[y]=dis[x]+e[i].w;
		dfs(y,x,cn);
	}
}
PII len(int x,int i){
	for(int i=1;i<=n;++i)	dis[i]=0;
	dis[root=0]=-1, dfs(x,0,i), tmp=x;
	for(int i=1;i<=n;++i)	dis[i]=0;
	dis[root=0]=-1, dfs(tmp,0,i);
	int minn=INF, y=root;
	while(true){
		minn=min(max(dis[y],dis[root]-dis[y]),minn);
		if(y==tmp)	break;
		y=fa[y];
	}
	return mk(minn,dis[root]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n;
	for(int i=1,x,y,z;i<n;++i) cin>>x>>y>>z, add(x,y,z), add(y,x,z);
	for(int i=0;i<n-1;++i){
		// cout<<i<<" "<<e[i<<1].u<<" "<<e[i<<1].v<<endl;
		PII len1=len(e[i<<1].u,i<<1), len2=len(e[i<<1].v,i<<1);
		// cout<<len1.fi<<" "<<len1.se<<" "<<len2.fi<<" "<<len2.se<<endl;
		ans=min(ans,max(max(len1.se,len2.se),len1.fi+len2.fi+e[i<<1].w));
	}
	cout<<ans<<endl;
	return 0;
}