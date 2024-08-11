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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6;
const int MOD = 1e9 + 7;

int p[N], mu[N], cnt, f[N], invf[N], g[N], invg[N];
int ksm(int x, int m){
	int ans = 1;
	while(m){ if(m&1) ans = ans*x%MOD; x=x*x%MOD; m>>=1;}
	return ans;
}
void init(){
	mu[1] = 1;
	for(int i=2;i<=M;++i){
		if(!p[i])   mu[p[++cnt] = i] = -1;
		for(int j=1;j<=cnt&&i*p[j]<=M;++j){
			p[i*p[j]] = 1;
			if(i%p[j]==0)   break;
			mu[i*p[j]] = -mu[i];
		}
	}
}
int t, n, m;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); init();
	f[1] = 1; for(int i=2;i<=M;++i) f[i] = (f[i-1] + f[i-2]) %MOD;
	invf[0] = 1; for(int i=1;i<=M;++i)  invf[i] = ksm(f[i], MOD-2);
	for(int i=0;i<=M;++i)   g[i] = 1;
	for(int d=1;d<=M;++d)
		for(int k=1;k*d<=M;++k)
			g[k*d] = g[k*d] * (mu[k]==0?1:(mu[k]==-1?invf[d]:f[d])) % MOD;
	for(int i=1;i<=M;++i)	g[i] = g[i] * g[i-1] % MOD;
	for(int i=0;i<=M;++i)	invg[i] = ksm(g[i], MOD-2);
	cin>>t;
	while(t--){
		cin>>n>>m;
		int mn = min(n, m), ans = 1;
		for(int l=1; l<=mn; ++l){
			int r = min(n/(n/l), m/(m/l));
			ans = ans * ksm(g[r] * invg[l-1] % MOD, (n/l) * (m/l)) % MOD;
			l=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}