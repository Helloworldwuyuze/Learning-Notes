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
const int N = 2e3 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 9;

int n, k;
int dp[N][N], f[N], ans[N], a[N], b[N], s[N], fact[N], infact[N];

int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x=1ll*x*x%MOD)	if(m & 1)	ans = 1ll*ans*x%MOD;
	return ans;
}
int C(int n,int m){
	return 1ll * fact[n] * infact[n-m] % MOD * infact[m] % MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	cin>>b[i];
	sort(a+1, a+1+n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)	s[i] += a[i] >= b[j];
	for(int i=0;i<=n;++i)	dp[i][0] = 1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			dp[i][j] = (dp[i-1][j] + 1ll * (s[i] - (j-1)) * dp[i-1][j-1] % MOD) % MOD;
	fact[0] = 1;
	for(int i=1;i<=n;++i)	fact[i] = 1ll * fact[i-1] * i % MOD;
	infact[n] = ksm(fact[n], MOD-2);
	for(int i=n-1;i>=0;--i)	infact[i] = 1ll * infact[i+1] * (i+1) % MOD;
	for(int i=0;i<=n;++i)	f[i] = 1ll * fact[n-i] * dp[n][i];
	k = (k+n)/2;
	for(int i=n;i>=k;--i){
		ans[i] = f[i];
		for(int j=i+1;j<=n;++j)
			ans[i] = (ans[i]-ans[j] * C(j, i)%MOD+MOD)%MOD;
	}
	cout<<ans[k]<<endl;
	return 0;
}