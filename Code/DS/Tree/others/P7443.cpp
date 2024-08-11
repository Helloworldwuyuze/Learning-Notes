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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

bool f[N], t, arr[N];
int T, fa[N], n, dep[N], s[N], ls[N], rs[N], siz[N];
long long A, B, mnu[N], mnv[N], a[N];
vector<int> g[N];

void dfs(int x){
	dep[x] = dep[fa[x]] + 1;
	bool flag = false;
	for(int y:g[x])
		dfs(y), flag |= f[y], s[x] += f[y];
	f[x] = !flag;
}

void _dfs(int x, bool wh){// wh为0：Alice
	if(!wh)	arr[x] = true;
	for(int y:g[x])
		if(s[x] == 1 && wh && f[y] || !wh)	_dfs(y, !wh);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>t>>A>>B;
		for(int i=1;i<=n;++i)
			mnv[i] = mnu[i] = INF, f[i] = arr[i] = false, s[i] = ls[i] = rs[i] = siz[i] = 0, g[i].clear();
		for(int i=2;i<=n;++i){
			cin>>fa[i], g[fa[i]].pb(i);
			rs[i] = ls[fa[i]], ls[fa[i]] = i;
			++siz[fa[i]];
		}
		for(int i=1;i<=n;++i)	cin>>a[i];
		dfs(1);
		if(f[1] == t){ cout<<0<<endl; continue;}
		_dfs(1, t);
		// for(int i=1;i<=n;++i)	cout<<arr[i]<<" ";
		// cout<<endl;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(int i=n;i;--i){
			if(arr[i])	mnu[i] = min(mnu[i], a[i]);
			if(f[i])	mnv[i] = min(mnv[i], a[i]);
			if(siz[i]){
				long long mmnu = mnu[ls[i]], mmnv = mnv[ls[i]];
				for(int j=rs[ls[i]]; j; j=rs[j]){
					if(mmnu != INF && mnv[j] != INF)	ans = min(ans, mmnu*A + mnv[j]*B);
					if(mnu[j] != INF && mmnv != INF)	ans = min(ans, mnu[j]*A + mmnv*B);
					mmnu = min(mmnu, mnu[j]), mmnv = min(mmnv, mnv[j]);
				}
				mnu[i] = min(mnu[i], mmnu), mnv[i] = min(mnv[i], mmnv);
				if(arr[i] && mmnv != INF)	ans = min(ans, A*a[i] + B*mmnv);
			}
		}
		if(ans == 0x3f3f3f3f3f3f3f3f)	cout<<-1<<endl;
		else	cout<<ans<<endl;
	}
	return 0;
}