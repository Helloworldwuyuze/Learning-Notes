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
const int N = 6e5 + 10;
const int M = 5e5 + 10;
const int MAXN = 20;

int n,val[N];
vector<int> g[N];

int t[N*MAXN][2], w[N*MAXN], sum[N*MAXN], idx;
#define ls(p) t[p][0]
#define rs(p) t[p][1]
int mknode(){
	++idx, ls(idx)=rs(idx)=w[idx]=sum[idx]=0;
	return idx;
}
void push_up(int p){
	w[p]=sum[p]=0;
	if(ls(p))	w[p]+=w[ls(p)], sum[p]^=sum[ls(p)]<<1;
	if(rs(p))	w[p]+=w[rs(p)], sum[p]^=(sum[rs(p)]<<1)|(w[rs(p)]&1);
	w[p]&=1;
}
void alladd(int p){
	swap(ls(p), rs(p));
	if(ls(p))	alladd(ls(p));
	push_up(p);
}
void update(int &p,int x,int dep){
	if(!p)	p=++idx;
	if(dep>MAXN)	return (void)(++w[p]);
	update(t[p][x&1],x>>1,dep+1);
	push_up(p);
}
int merge(int p,int q){
	if(!p||!q)	return p+q;
	w[p]+=w[q], sum[p]^=sum[q];
	ls(p)=merge(ls(p),ls(q)), rs(p)=merge(rs(p),rs(q));
	return p;
}
#undef ls
#undef rs

long long ans=0;
int root[N];
void dfs(int x,int fa){
	for(int y:g[x]){
		if(y==fa)	continue;
		dfs(y,x);
		root[x]=merge(root[x],root[y]);
	}
	alladd(root[x]);
	update(root[x], val[x], 0);
	ans+=sum[root[x]];
	// cout<<x<<" "<<sum[root[x]]<<" "<<val[x]<<" "<<root[x]<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>val[i];
	for(int i=2,x;i<=n;++i)	cin>>x, g[i].pb(x), g[x].pb(i);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}