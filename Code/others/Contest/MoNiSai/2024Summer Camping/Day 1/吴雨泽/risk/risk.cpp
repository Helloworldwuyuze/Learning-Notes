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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 2e6 + 10;

int n, m;
int fa[N];
struct edge{
	int u, v, w;
	bool operator <(const edge &other) const { return w < other.w; }
}e[M];

int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

signed main(){
	freopen("risk.in","r",stdin);
	freopen("risk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1, e+1+m);
	long long cnt = 0, ans = 0;
	for(int i=1;i<=n;++i)	fa[i] = i;
	for(int i=1;i<=m;++i){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fx = find(u), fy = find(v);
		if(fx == fy)	continue;
		fa[fx] = fy;
		++cnt, ans += w;
		if(cnt == n-1)	break;
	}
	cout<<ans<<endl;
	return 0;
}
