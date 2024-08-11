#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
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
#define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, a[M], tot, fa[N], ans, m;
struct edge{
	int u, v, w;
	bool f;
	bool operator <(const edge &other) const { return w < other.w; }
}e[M];

int find(int x){ return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
vector<PII> g;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	if(n<=1000){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				e[++tot] = edge{i, j, a[i]*a[j], false};
		sort(e+1, e+1+tot);
		for(int i=1;i<=n;++i)	fa[i] = i;
		for(int i=1;i<=tot;++i){
			int x = e[i].u, y = e[i].v;
			int fx = find(x), fy = find(y);
			if(fx == fy)	continue;
			fa[fx] = fy, ans += e[i].w, e[i].f = true;
			--m;
			g.pb(mk(x, y));
		}
		for(int i=1;i<=tot && m;++i)
			if(!e[i].f)	ans += e[i].w, --m, g.pb(mk(e[i].u, e[i].v));
		cout<<ans<<endl;
		for(PII x:g)	cout<<x.fi<<" "<<x.se<<endl;
	}
	return 0;
}