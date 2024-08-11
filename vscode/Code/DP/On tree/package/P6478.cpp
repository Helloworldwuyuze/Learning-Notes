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
const int N = 5e3 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

int n, dp[N][N], siz[N], sz[N], f[N], g[N], m, tmp[N], fact[N], infact[N];
bool bl[N];
char s[N];
vector<int> v[N];

void dfs(int x,int fa){
	siz[x] = 1, sz[x] = bl[x];
	dp[x][0] = 1;
	for(int y:v[x]){
		if(y == fa)	continue;
		dfs(y, x);
		siz[x] += siz[y], sz[x] += sz[y];
		for(int i=0;i<=siz[x];++i)	tmp[i] = 0;
		for(int i=0; i<=min(siz[x], m); ++i) if(dp[x][i])
			for(int j=0; j+i<=m && j<=siz[y]; ++j) if(dp[y][j])
				tmp[i+j] = (tmp[i+j] + dp[x][i] * dp[y][j] % MOD) % MOD;
		for(int i=0;i<=siz[x];++i)	dp[x][i] = tmp[i];
	}
	for(int i=min(sz[x], siz[x] - sz[x]); i; --i)
		dp[x][i] = (dp[x][i] + dp[x][i-1]*((bl[x] ? siz[x] - sz[x] : sz[x]) - (i-1))%MOD)%MOD;
}

int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x=x*x%MOD)	if(m & 1)	ans=ans*x%MOD;
	return ans;
}

int C(int n,int m){
	return fact[n]*infact[n-m]%MOD*infact[m]%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>(s+1); m = n>>1;
	fact[0] = 1;
	for(int i=1;i<=n;++i)	fact[i] = fact[i-1]*i%MOD;
	infact[n] = ksm(fact[n], MOD-2);
	for(int i=n-1;i>=0;--i)	infact[i] = infact[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;++i)	bl[i] = s[i] == '1';
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, v[x].pb(y), v[y].pb(x);
	dfs(1, 0);
	for(int i=0;i<=m;++i)	f[i] = dp[1][i]*fact[m-i]%MOD;
	for(int i=0;i<=m;++i)
		for(int j=i;j<=m;++j)
			g[i] = (g[i]+((j-i&1) ? MOD-1 : 1)*C(j, i)%MOD*f[j]%MOD)%MOD;
	for(int i=0;i<=m;++i)	cout<<g[i]<<endl;
	return 0;
}