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
// #define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e7 + 10;
const int M = 1e7;
const int MOD = 998244353;

int p[N], cnt, F[N], f[N];
int ksm(int x,int m){
	int ans = 1;
	for(; m; x=x*x%MOD, m>>=1)	if(m&1)	ans = ans*x%MOD;
	return ans;
}
int n, k;
int mod(int x){ return (x%MOD+MOD)%MOD;}
void init(){
	f[1] = F[1] = 1;
	for(int i=2;i<=M;++i){
		if(!p[i])	p[++cnt] = i, F[i] = ksm(i, k), f[i] = i-1;
		for(int j=1;j<=cnt&&i*p[j]<=M;++j){
			p[i*p[j]] = 1, F[i*p[j]] = F[i] * F[p[j]] % MOD;
			if(i%p[j]==0){ f[i*p[j]] = ((i/p[j])%p[j])?mod(-p[j]*f[i/p[j]]):0; break;}
			f[i*p[j]] = f[i] * f[p[j]] % MOD;
		}
	}
	// for(int i=1;i<=10;++i)	cout<<f[i]<<" ";
	// cout<<endl;
	for(int i=1;i<=M;++i)	f[i] = (f[i-1] + F[i] * f[i] % MOD) % MOD, F[i] = (F[i] + F[i-1])%MOD;
	for(int i=1;i<=M;++i)	F[i] = (F[i] + F[i-1])%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k; int ans = 0; k %= MOD-1;
	init();
	for(int l = 1, r = n/(n/l); l<=n;l = r+1, r = l>n?0:n/(n/l))
		ans = (ans + mod(f[r] - f[l-1]) * mod(F[n/l*2] - 2*F[n/l]) % MOD) % MOD;
	cout<<ans<<endl;
	return 0;
}