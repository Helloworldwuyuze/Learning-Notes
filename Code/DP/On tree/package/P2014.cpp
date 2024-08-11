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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e2 + 10;
const int M = 1e6 + 10;

int n, m;
int f[N][N], val[N], siz[N];
vector<int> g[N];

void dfs(int x){
	siz[x] = 1;
	f[x][1] = val[x];
	for(int y:g[x]){
		dfs(y);
		siz[x] += siz[y];
		for(int i=min(siz[x], m+1);i;--i)
			for(int j=1; j+i<=m+1 && j<=siz[y]; ++j)
				f[x][i+j] = max(f[x][i+j], f[x][i] + f[y][j]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1, fa;i<=n;++i)	cin>>fa>>val[i], g[fa].pb(i);
	dfs(0);
	cout<<f[0][m+1]<<endl;
	return 0;
}