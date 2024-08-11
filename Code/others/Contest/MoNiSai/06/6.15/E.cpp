#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e4 + 10;
const int M = 5e2 + 10;

int n, m, d[N], f[N][M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)   cin>>d[i];
	for(int i=1;i<=n;++i)
		for(int j=0;j<=m;++j){
			if(j==0)	f[i][j] = max(f[i-1][j], f[i][j]);
			else	f[i][j] = max(f[i][j], f[i-1][j-1] + d[i]);
			f[i+j][0] = max(f[i+j][0], f[i][j]);
		}
	cout<<f[n][0]<<endl;
	return 0;
}