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
const int MOD = 1e9 + 7;

int n, m, x;
int fact[N], infact[N];

int ksm(int x,int m){
	int ans = 1;
	for(;m;m>>=1,x=x*x%MOD)	if(m&1)	ans=ans*x%MOD;
	return ans;
}

int C(int n,int m){
	return fact[n]*infact[n-m]%MOD*infact[m]%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x, n-=x;
	fact[0] = 1; for(int i=1;i<=n;++i)	fact[i] = fact[i-1]*i%MOD;
	infact[n] = ksm(fact[n], MOD-2); for(int i=n-1;i>=0;--i)	infact[i] = infact[i+1]*(i+1)%MOD;
	cout<<C(n-1, m-1)<<endl;
	return 0;
}