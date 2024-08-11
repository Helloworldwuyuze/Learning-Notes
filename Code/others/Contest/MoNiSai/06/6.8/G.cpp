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
const int N = 5e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

int n,a[N];
int q[N], he = 1, re, f[N][2], s[N][2];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	f[0][0] = s[0][0] = 1;
	for(int i=1;i<=n;++i){
		while(re>=he&&a[q[re]]>=a[i])	--re;
		if(re<he){	for(int x:{0, 1})	f[i][x] = s[i-1][x^1]*a[i]%MOD;}
		else{	for(int x:{0, 1})	f[i][x] = (f[q[re]][x] + (s[i-1][x^1] - s[q[re]-1][x^1] + MOD) * a[i] % MOD) %MOD;}
		q[++re] = i;
		for(int x:{0, 1})	s[i][x] = (s[i-1][x] + f[i][x]) % MOD;
	}
	int ans = (f[n][0] - f[n][1] + MOD) % MOD;
	if(n&1)	ans = ans * (MOD-1) % MOD;
	cout<<ans<<endl;
	return 0;
}