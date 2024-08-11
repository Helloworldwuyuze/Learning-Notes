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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

PII lim[N];
int n, a[N], m, ans, sum[N];
bool flag[N];
map<PII, bool> ma;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>lim[i].fi>>lim[i].se;
		if(ma[lim[i]])	continue;
		++sum[lim[i].fi], ++sum[lim[i].se];
		ma[lim[i]] = true;
	}
	for(int i=1;i<=n;++i)
		if(sum[i] > 2){
			cout<<0<<endl;
			return 0;
		}
	for(int i=1;i<=n;++i)	a[i] = i;
	do{
		bool ok = true;
		for(int i=1;i<=m;++i)
			flag[i] |= a[lim[i].fi] == lim[i].se || a[lim[i].se] == lim[i].fi, ok &= flag[i];
		ans += ok;
		for(int i=1;i<=m;++i)	flag[i] = false;
	}while(next_permutation(a+1, a+1+n));
	cout<<ans<<endl;
	return 0;
}

