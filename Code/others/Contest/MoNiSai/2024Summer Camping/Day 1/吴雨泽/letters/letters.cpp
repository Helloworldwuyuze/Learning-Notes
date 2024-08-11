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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

int sum[N], n, m, k, fact[N], infact[N], base[N], inbase[N];

inline int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x = x*x%MOD) if(m&1) ans = ans*x%MOD;
	return ans;
}

inline int A(int n,int m){
	if(n<m)	return 0;
	return fact[n]*infact[n-m]%MOD;
}
inline int C(int n,int m){
	if(n<m)	return 0;
	return fact[n]*infact[n-m]%MOD*infact[m]%MOD;
}

int ans, a[N], t[N];
bool vis[N];
bool cmp(int *x,int *y){
	for(int i=0;i<m;++i)
		if(x[i] != y[i])	return false;
	return true;
}

int chk(){
	int sum = 0;
	for(int i=1;i<=n;++i)	vis[i] = false;
//	for(int i=1;i<=n;++i)	cerr<<a[i]<<" ";
//	cout<<endl;
	for(int i=1;i+m-1<=n;++i){
		bool flag = true;
		for(int j=i-1;j && j>=i-m+1;--j)
			if(cmp(a+i, a+j) && vis[j])	flag = false;
//		cout<<i<<" "<<flag<<endl;
		if(!flag)	continue;
		for(int j=1;j<=k;++j)	t[j] = 0;
		for(int j=i;j<=i+m-1;++j)
			++t[a[j]], flag &= t[a[j]]<=2;
		vis[i] = true;
		sum += flag;
	}
//	cout<<sum<<endl;
	return sum;
}

void f(int x){
	if(x==n+1)	return (void)(ans += chk());
	for(int i=1;i<=k;++i)
		a[x] = i, f(x+1);
}

signed main(){
	freopen("letters.in","r",stdin);
	freopen("letters.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
//	fact[0] = base[0] = 1;
//	for(int i=1;i<=MAXN;++i)	base[i] = base[i-1]*2%MOD;
//	inbase[MAXN] = ksm(base[MAXN], MOD-2);
//	for(int i=MAXN-1;i>=0;--i)	inbase[i] = inbase[i+1]*2%MOD;
//	for(int i=1;i<=MAXN;++i)	fact[i] = fact[i-1]*i%MOD;
//	infact[MAXN] = ksm(fact[MAXN], MOD-2);
//	for(int i=MAXN-1;i>=0;--i)	infact[i] = infact[i+1]*(i+1)%MOD;
////	for(int i=0;i<=10;++i)	cout<<fact[i]<<" "<<infact[i]<<endl;
//	for(int i=0;i*2<=m;++i)
//		sum[i] = fact[m]*C(k, m-2*i)%MOD*C(k-(m-2*i),i)%MOD*inbase[i]%MOD + sum[i-1];
//	cout<<sum[m>>1]<<endl;
	f(1);
	cout<<ans<<endl;
	return 0;
}

