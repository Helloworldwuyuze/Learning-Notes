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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e3 + 10;
const int M = 1e2 + 10;
const int NN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 233;

int n, a[N], len, q, k[N], b[N], m, sum[N], pre[N][N];
long long s[NN], base[NN], inbase[NN], s2[NN], base2[NN];
vector<int> g[N];

int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x=1ll*x*x%MOD)	ans=1ll*ans*x%MOD;
	return ans;
}
int Hash(int l,int r){
	return (s[r]-1ll*s[l-1]*base[r-l+1]%MOD+MOD)%MOD;
}
int Hash2(int l,int r){
	return (s2[r]-1ll*s2[l-1]*base2[r-l+1]%MOD2+MOD2)%MOD2;
}
bool cmp(int x,int y){
	return Hash(x,x+len-1) == Hash(y,y+len-1) && Hash2(x,x+len-1) == Hash2(y,y+len-1);
}

int main(){
	freopen("luck.in","r",stdin);
	freopen("luck.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>len;
	for(int i=1;i<=n;++i)	cin>>a[i], b[i] = a[i];
	cin>>q;
	for(int i=1;i<=q;++i)	cin>>k[i];
	sort(b+1, b+1+n);
	m = unique(b+1, b+1+n) - b - 1;
	for(int i=1;i<=n;++i)	a[i] = lower_bound(b+1, b+1+m, a[i]) - b;
	if(q == 1 && k[1] == 0){
		base[0] = base2[0] = 1;
		for(int i=1;i<=n;++i)	base[i] = 1ll*base[i-1]*m%MOD;
		for(int i=1;i<=n;++i)	base2[i] = 1ll*base2[i-1]*m%MOD2;
		for(int i=1;i<=n;++i)	s[i] = (s[i-1]*m%MOD+(a[i]-1))%MOD;
		for(int i=1;i<=n;++i)	s2[i] = (s2[i-1]*m%MOD2+(a[i]-1))%MOD2;
//		cout<<m<<endl;
//		for(int i=1;i<=m;++i)	cout<<b[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;++i)	cout<<s[i]<<" ";
//		cout<<endl;
		for(int i=1;i+len-1<=n;++i)
			for(int j=1;j+len-1<=n;++j)
				if(i!=j){
					sum[i] += cmp(i, j);
				}
		for(int i=1;i+len-1<=n;++i)	cout<<sum[i]<<" ";
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)	g[a[i]].pb(i);
	for(int i=1;i+len-1<=n;++i){
		for(int j=0;j<len;++j){
			int x = i+j;
			for(int k=0;k<g[a[x]].size();++k){
				int y = g[a[x]][k];
				if(x==y || y<=j)	continue;
				++sum[y-j];
			}
		}
		for(int j=1;j+len-1<=n;++j)
			if(i!=j)	++pre[i][sum[j]+1];
		for(int j=1;j<=len+1;++j)	pre[i][j] += pre[i][j-1];
		for(int j=1;j<=n;++j)	sum[j] = 0;
	}
	for(int j=1;j<=q;++j){
		for(int i=1;i+len-1<=n;++i)	cout<<pre[i][len+1]-pre[i][len-k[j]]<<" ";
		cout<<endl;
	}
	return 0;
}

