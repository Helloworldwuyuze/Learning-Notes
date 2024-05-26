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
const int N = 5e5 + 10;
const int M = 5e5 + 10;
const int MAXN = 20;

int t[N*25][2], root[N], idx, w[N*25], sum[N*25];
vector<int> g[N];
int fa[N], n, val[N], tag[N], m;

int mknode(){
	++idx, w[idx]=t[idx][0]=t[idx][1]=sum[idx]=0;
	return idx;
}
#define ls t[p][0]
#define rs t[p][1]
void maintain(int p){
	w[p]=sum[p]=0;
	if(ls)	w[p]+=w[ls], sum[p]^=sum[ls]<<1;
	if(rs)	w[p]+=w[rs], sum[p]^=(sum[rs]<<1)|(w[rs]&1);
	w[p]&=1;
}
void update(int &p,int x,int dep,int k){
	if(!p)	p=mknode();
	if(dep>MAXN)	return (void)(w[p]+=k);
	update(t[p][x&1],x>>1,dep+1,k);
	maintain(p);
}
void alladd(int p){
	swap(ls,rs);
	if(ls)	alladd(ls);
	maintain(p);
}
#undef ls
#undef rs

void dfs(int x,int fat){
	fa[x]=fat;
	for(int y:g[x])	if(y!=fat)	dfs(y,x);
}
void modify(int x,int k){
	if(x==0)	return ;
	if(x==1)	return (void)(val[x]+=k);
	update(root[fa[x]],val[x]+tag[fa[x]],0,1);
	update(root[fa[x]],val[x]+tag[fa[x]]+k,0,1);
	val[x]+=k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1,0);
	for(int i=1;i<=n;++i)	cin>>val[i];
	for(int i=1;i<=n;++i){
		for(int j:g[i])
			if(j!=fa[i])	update(root[i],val[j],0,1);
	}
	while(m--){
		int op, x, v;
		cin>>op;
		if(op==1)	cin>>x, alladd(root[x]), ++tag[x], modify(fa[x],1);
		else if(op==2)	cin>>x>>v, modify(x,-v);
		else	cin>>x, cout<<(sum[root[x]]^(val[fa[x]]+tag[fa[fa[x]]]))<<endl;
	}
	return 0;
}