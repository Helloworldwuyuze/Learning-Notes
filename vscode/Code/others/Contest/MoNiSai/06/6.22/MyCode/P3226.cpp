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
const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int MAXN = (1<<20);
const int MOD = 1e9 + 1;

bool g[MAXN+10], vis[N];
int n, ans = 1, lim[25];
int f[25][MAXN], row;

void build(int x){
	row = 0;
	for(int i = x; i<=n; i*=2){
		lim[++row] = 0;
		for(int j = i; j<=n; j*=3)
			++lim[row], vis[j] = true;
		lim[row] = (1<<lim[row]);
	}
	// cout<<row<<endl;
	// for(int i=1;i<=row;++i)
	// 	cout<<lim[i]<<" ";
	// cout<<endl;
}
int solve(){
	for(int i=1;i<=row;++i)
		for(int j=0;j<lim[i];++j)
			f[i][j] = 0;
	for(int i=0;i<lim[1];++i)	f[1][i] = g[i];
	for(int i=2;i<=row;++i)
		for(int j=0;j<lim[i];++j){
			if(!g[j])	continue;
			for(int k=0;k<lim[i-1];++k)
				if(!(j&k)&&g)	f[i][j] = (f[i][j] + f[i-1][k])%MOD;
		}
	int ans = 0;
	for(int i=0;i<lim[row];++i)
		ans = (ans + f[row][i])%MOD;
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=0;i<MAXN;++i)	g[i] = ((i<<1) & (i)) ? 0 : 1;
	for(int i=1;i<=n;++i)
		if(!vis[i])	build(i), ans = ans*solve()%MOD;
	cout<<ans<<endl;
	return 0;
}