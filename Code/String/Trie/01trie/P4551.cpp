#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<bitset>

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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;

struct _2{
	bool b[31];
};
int n;
vector<PII> g[N];
int val[N], ans;

void dfs(int x,int fa){
	for(PII y:g[x]){
		if(y.fi==fa)	continue;
		val[y.fi]=val[x]^y.se;
		dfs(y.fi,x);
	}
}

int t[N][2], idx;
void insert(_2 x){
	int p=0;
	for(int i=0;i<31;++i)	p=(t[p][x.b[i]]?t[p][x.b[i]]:(t[p][x.b[i]]=++idx));
}
int query(_2 x){
	int p=0, dep=31, ans=0;
	for(int i=0;i<31;++i, --dep)
		if(t[p][!x.b[i]])	ans+=(1<<dep-1), p=t[p][!x.b[i]];
		else if(t[p][x.b[i]])	p=t[p][x.b[i]];
		else	return ans;
	return ans;	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	dfs(1,0);
	for(int i=1;i<=n;++i){
		_2 x;
		for(int j=30;j>=0;--j)
			x.b[j]=val[i]%2, val[i]>>=1;
		// for(int j=0;j<31;++j)	cout<<x.b[j];
		// cout<<endl;
		ans=max(ans,query(x));
		insert(x);
	}
	cout<<ans<<endl;
	return 0;
}