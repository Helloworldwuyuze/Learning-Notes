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
const int N = 2e3 + 10;
const int M = 1e6 + 10;

int n, m, q, x, y;
int f[N][N], c[N];

signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>c[i];
	if(n<=2000 && m<=2000) {
		memset(f, 0x3f, sizeof(f));
		f[1][1] = 0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(i!=1)	f[i][j] = min(f[i][j], f[i-1][j]+c[j]);
				if(j!=1)	f[i][j] = min(f[i][j], f[i][j-1]+i*i);
			}
		}
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<f[x][y]<<endl;
		}
	}else{
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<1ll*c[y]*(x-1)+(y-1)<<endl;
		}
	}
	return 0;
}

