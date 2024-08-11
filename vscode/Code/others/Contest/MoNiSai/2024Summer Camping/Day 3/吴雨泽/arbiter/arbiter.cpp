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
#include<unordered_map>

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
#define re register

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int MOD1[] = {10000000 + 19, 10000000 + 103};
const int MOD2[] = {10000000 + 987, 10000000+993};
const int MAXN = 1e7 + 1e3;

int n, a[N][N], b[N][N], ha[N][N][2], hb[N][N][2], tmpa[N][N][2], tmpb[N][N][2];
int c[N*N*2], m, fa[N][N][2], fb[N][N][2];
int base[N][2][2];

inline int Hasha(int x, int l, int r, bool f){
	return (ha[x][r][f] - 1ll*ha[x][l-1][f]*base[r-l+1][0][f]%MOD1[f]+MOD1[f])%MOD1[f];
}
inline int Hashb(int x, int l, int r, int f){
	return (hb[x][r][f] - 1ll*hb[x][l-1][f]*base[r-l+1][0][f]%MOD1[f]+MOD1[f])%MOD1[f];
}
inline int HashTmpa(int l,int r,int y, int f){
	return (tmpa[r][y][f]-1ll*tmpa[l-1][y][f]*base[r-l+1][1][f]%MOD2[f]+MOD2[f])%MOD2[f];
}
inline int HashTmpb(int l,int r,int y, int f){
	return (tmpb[r][y][f]-1ll*tmpb[l-1][y][f]*base[r-l+1][1][f]%MOD2[f]+MOD2[f])%MOD2[f];
}

unordered_map<long long, bool> ma;

inline bool chk(int x){
	for(re int f=0;f<=1;++f)
		for(re int i=1;i<=n;++i)
			for(re int j=1;j+x-1<=n;++j){
				tmpa[i][j][f] = Hasha(i, j, j+x-1, f);
				tmpb[i][j][f] = Hashb(i, j, j+x-1, f);
			}
	for(re int f=0;f<=1;++f)
		for(re int j=1;j+x-1<=n;++j)
			for(re int i=1;i<=n;++i){
				tmpa[i][j][f] = (1ll*tmpa[i-1][j][f]*MOD1[f]%MOD2[f]+tmpa[i][j][f])%MOD2[f];
				tmpb[i][j][f] = (1ll*tmpb[i-1][j][f]*MOD1[f]%MOD2[f]+tmpb[i][j][f])%MOD2[f];
			}
	ma.clear();
	for(re int f=0;f<=1;++f)
		for(re int j=1;j+x-1<=n;++j)
			for(re int i=1;i+x-1<=n;++i){
				fa[i][j][f] = HashTmpa(i, i+x-1, j, f);
				fb[i][j][f] = HashTmpb(i, i+x-1, j, f);
			}
	for(re int i=1;i+x-1<=n;++i)
		for(re int j=1;j+x-1<=n;++j)
			ma[(1ll*fa[i][j][0]<<32)+fa[i][j][1]] = true;
	for(re int i=1;i+x-1<=n;++i)
		for(re int j=1;j+x-1<=n;++j)
			if(ma[(1ll*fb[i][j][0]<<32)+fb[i][j][1]])	return true;
	return false;
}

bool prime(int x){
	for(re int i=2;i*i<=x;++i)
		if(x%i==0)	return false;
	return true;
}

signed main(){
	freopen("arbiter0_6.in","r",stdin);
	freopen("arbiter.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			cin>>a[i][j], c[++m] = a[i][j];
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			cin>>b[i][j], c[++m] = b[i][j];
	sort(c+1, c+1+m);
	m = unique(c+1, c+1+m) - c - 1;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j){
			a[i][j] = lower_bound(c+1, c+1+m, a[i][j]) - c - 1;
			b[i][j] = lower_bound(c+1, c+1+m, b[i][j]) - c - 1;
		}
	base[0][0][0] = base[0][0][1] = base[0][1][0] = base[0][1][1] = 1;
	for(re int f=0;f<=1;++f)
		for(re int i=1;i<=n;++i)	base[i][0][f] = 1ll*base[i-1][0][f]*m%MOD1[f];
	for(re int f=0;f<=1;++f)
		for(re int i=1;i<=n;++i)	base[i][1][f] = 1ll*base[i-1][1][f]*MOD1[f]%MOD2[f];
	for(re int f=0;f<=1;++f)
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j){
				ha[i][j][f] = (1ll*ha[i][j-1][f]*m%MOD1[f] + a[i][j])%MOD1[f];
				hb[i][j][f] = (1ll*hb[i][j-1][f]*m%MOD1[f] + b[i][j])%MOD1[f];
			}
	int l = 0, r = n;
	while(l < r){
		int mid = l+r+1>>1;
		if(chk(mid))	l = mid;
		else	r = mid-1;
	}
	cout<<l<<endl;
	return 0;
}
