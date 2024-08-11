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
const int N = 1e2 + 10;
const int M = 1e6 + 10;

int n, m, v[N], f[4*N][N], w[N], minn = INF, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(f, -0x3f, sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>w[i]>>v[i], minn = min(minn, w[i]);
	for(int i=1;i<=n;++i)	w[i] -= minn-1;
	for(int i=0;i<=4*n;++i)	f[i][0] = 0;
	for(int i=1;i<=n;++i){
		for(int j=4*n;j>=w[i];--j)
			for(int k=1;k*(minn-1)+j<=m;++k)
				f[j][k] = max(f[j][k], f[j-w[i]][k-1]+v[i]), ans = max(ans, f[j][k]);
		// for(int j=0;j<=m;++j,cout<<endl)
		// 	for(int k=1;k<=n;++k)
		// 		cout<<f[j][k]<<" ";
		// cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}