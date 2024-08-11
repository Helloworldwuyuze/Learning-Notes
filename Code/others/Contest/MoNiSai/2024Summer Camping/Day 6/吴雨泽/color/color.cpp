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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, a[N], ans, T, f[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n; ans = 0;
		for(int i=1;i<=n;++i)	cin>>a[i];
		f[1] = a[1]; ans = f[1];
		for(int i=2;i<=n;++i){
			f[i] = max(f[i-2], f[i-3]+min(a[i-1],a[i-2]))+a[i];
			ans = max(ans, f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

