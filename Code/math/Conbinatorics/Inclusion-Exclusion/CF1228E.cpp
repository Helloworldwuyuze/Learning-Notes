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
const int N = 2.5e2 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, k, ans, sum;
int c[N][N];

int ksm(int x, int m){
	int ans = 1;
	for(; m; m>>=1, x=x*x%MOD)	if(m & 1)	ans = ans*x%MOD;
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	c[0][0] = 1;
	for(int i=1;i<=N-10;++i)
		for(int j=0;j<=i;++j)
			if(j == 0)	c[i][j] = 1;
			else	c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
	cin>>n>>k;
	ans = ksm((ksm(k, n) - ksm(k-1, n) + MOD)%MOD, n);
	for(int i=1;i<=n;++i)
		sum = (sum + ((i&1)*2-1) * c[n][i] * ksm((ksm(k, n-i) * ksm(k-1, i) % MOD - ksm(k-1, n) + MOD)%MOD, n) % MOD + MOD)%MOD;
	cout<<(ans - sum + MOD)%MOD<<endl;
	return 0;
}