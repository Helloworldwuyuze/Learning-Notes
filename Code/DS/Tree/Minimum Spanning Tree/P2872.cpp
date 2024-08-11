#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
typedef pair<double,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int n,m,x[N],y[N],fa[N],tot;
PIII e[M];
double ans;

int find(int x){ return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	fa[i]=i;
	for(int i=1;i<=n;++i)	cin>>x[i]>>y[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)	e[++tot]=mk(sqrt(1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j])),mk(i,j));
	sort(e+1,e+1+tot);
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, fa[find(x)]=find(y);
	for(int i=1;i<=tot;++i){
		int u=e[i].se.fi, v=e[i].se.se;
		int fu=find(u), fv=find(v);
		if(fu==fv)	continue;
		++m; ans+=e[i].fi; fa[fu]=fv;
		if(m==n-1)	break;
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}