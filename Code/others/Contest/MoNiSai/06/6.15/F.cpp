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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e3 + 10;
const int M = 5e2 + 10;

int f[N][N], n, m, siz[N];
vector<PII> g[N];

void solve(int x,int fa){
	siz[x] = 1;
	for(PII y:g[x]){
		if(y.fi == fa)  continue;
		solve(y.fi, x);
		siz[x] += siz[y.fi];
		for(int j = max(siz[x], m); j>=0; --j)
			for(int k = max(j - siz[x] + siz[y.fi], 0ll); k <= min(j, siz[y.fi]); ++k)
				f[x][j] = max(f[x][j], f[y.fi][k] + f[x][j-k] + y.se * k * (m-k) + y.se * (siz[y.fi]-k) * (n-m-siz[y.fi]+k));	
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	solve(1, 0);
	cout<<f[1][m]<<endl;
	return 0;
}