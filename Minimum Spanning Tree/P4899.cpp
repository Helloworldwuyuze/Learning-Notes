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
const int N = 2e5 + 10;
const int M = 4e5 + 10;

struct edge{ int u,v,w;};

bool operator <(const edge x,const edge y){ return x.w<y.w;}

int n,m,q,x,y,tot1,tot2;
edge e1[N],e2[N];
vector<int> g1[N<<1],g2[N<<1];
int fa1[N<<1],fa2[N<<1],w1[N<<1],w2[N<<1];

int find1(int x){ return x==fa1[x]?fa1[x]:fa1[x]=find1(fa1[x]);}
int find2(int x){ return x==fa2[x]?fa2[x]:fa2[x]=find2(fa2[x]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)	cin>>x>>y, e1[i]=edge{x,y,min(x,y)}, e2[i]=edge{x,y,max(x,y)};

	sort(e1+1,e1+1+m), sort(e2+1,e2+1+m);
	for(int i=1;i<=n<<1;++i)	fa1[i]=fa2[i]=i;
	for(int i=1;i<=n;++i)	w1[i]=e1[i].w;
	for(int i=m;i;--i){
		int u=e1[i].u, v=e1[i].v;
		int fu=find1(u), fv=find1(v);
		if(fu==fv)	continue;
		++tot1; fa1[fu]=fa1[fv]=tot1;
		g1[tot1].pb(fu), g1[tot1].pb(fv), g1[fv].pb(tot1), g1[fu].pb(tot1);
		w1[tot1]=e1[i].w;
		if(tot1==2*n-1)	break;
	}
	for(int i=1;i<=n;++i)	w2[i]=e2[i].w;
	for(int i=1;i<=m;++i){
		int u=e2[i].u, v=e2[i].v;
		int fu=find2(u), fv=find2(v);
		if(fu==fv)	continue;
		++tot2; fa2[fu]=fa2[fv]=tot2;
		g2[tot2].pb(fu), g2[tot2].pb(fv), g2[fv].pb(tot2), g2[fv].pb(tot2);
		w2[tot2]=e2[i].w;
		if(tot2==2*n-1)	break;
	}

	while(q--){
		
	}
	return 0;
}