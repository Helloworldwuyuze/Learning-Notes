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
const int N = 4e2 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 7;

int f[N], C[N][N];
int n, m, c;

int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x=x*x%MOD)	if(m & 1)	ans = ans*x%MOD;
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	C[0][0] = 1;
	for(int i=1;i<=N-10;++i)
		for(int j=0;j<=i;++j)
			if(j == 0)	C[i][j] = 1;
			else	C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
	cin>>n>>m>>c;
	for(int i=1;i<=c;++i){
		int sum = 0;
		for(int k=1;k<=m;++k){
			// cout<<((k&1)*2-1)<<" "<<C[m][k]<<" "<<ksm((ksm(i+1, m-k)%MOD-1+MOD)%MOD, n)<<endl;
			sum = (sum + ((k&1)*2-1) * C[m][k] * ksm((ksm(i+1, m-k)%MOD-1+MOD)%MOD, n)%MOD + MOD) %MOD;
		}
		f[i] = (ksm((ksm(i+1, m)-1+MOD)%MOD, n)-sum+MOD)%MOD;
	}
	int ans = f[c], sum = 0;
	for(int i=1;i<=c;++i)
		sum = (sum + ((i&1)*2-1) * C[c][i] * f[c-i] % MOD + MOD) %MOD;
	cout<<(ans-sum+MOD)%MOD<<endl;
	return 0;
}