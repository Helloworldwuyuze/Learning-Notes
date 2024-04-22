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

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n,m,op;
char c[N];
vector<int> g[N];
bool exist[N];

namespace AC{
	int t[N][26], flag[N], val[N], tag[N], idx=1, cnt=0, fail[N];
	queue<int> q;
	void insert(char c[]);
	void build();
	void query(char c[]);
}
namespace ST{
	int maxx[N<<2];
	void update(int p,int l,int r,int x,int k);
	int query(int p,int l,int r,int left,int right);
}
namespace TC{
	int son[N],siz[N],dep[N],dfn[N],rk[N],fa[N],top[N],idx;
	void dfs1(int x,int fat);
	void dfs2(int x,int tp);
	int query(int x);
}

void ST::update(int p,int l,int r,int x,int k){
	// DBG;
	// cout<<p<<" "<<l<<" "<<r<<" "<<x<<" "<<k<<endl;
	if(l==r){ maxx[p]=k; return ;}
	int mid=l+r>>1;
	if(x<=mid)	update(p<<1,l,mid,x,k);
	else	update(p<<1|1,mid+1,r,x,k);
	maxx[p]=max(maxx[p<<1],maxx[p<<1|1]);
}
int ST::query(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return maxx[p];
	int mid=l+r>>1, res=0;
	if(left<=mid)	res=max(res,query(p<<1,l,mid,left,right));
	if(right>mid)	res=max(res,query(p<<1|1,mid+1,r,left,right));
	return res;
}

void AC::insert(char c[]){
	int len=strlen(c), p=1;
	for(int i=0;i<len;++i)
		p=(t[p][c[i]-'a'])?(t[p][c[i]-'a']):(t[p][c[i]-'a']=++idx);
	flag[p] = ++cnt, tag[cnt] = p; exist[p]=true;
}
void AC::build(){
	for(int i=0;i<26;++i)
		if(t[1][i])	q.push(t[1][i]), fail[t[1][i]]=1;
		else	t[1][i]=1;
	fail[1]=1;
	while(q.size()){
		int p=q.front(); q.pop();
		// cout<<p<<" ";
		for(int i=0;i<26;++i)
			if(t[p][i])	fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]);
			else	t[p][i]=t[fail[p]][i];
	}
	for(int i=2;i<=idx;++i)
		g[i].pb(fail[i]), g[fail[i]].pb(i);
}
void AC::query(char c[]){
	int ans=0, len=strlen(c), p=1;
	bool exi=false;
	for(int i=0;i<len;++i){
		p=t[p][c[i]-'a'];
		exi|=exist[p];
		ans=max(ans,TC::query(p));
		// cout<<ans<<endl;
	}
	if(exi)	cout<<ans<<endl;
	else	cout<<-1<<endl;
}

void TC::dfs1(int x,int fat){
	fa[x]=fat; siz[x]=1, dep[x]=dep[fat]+1;
	for(int y:g[x]){
		if(y==fat)	continue;
		exist[y]|=exist[x];
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])	son[x]=y;
	}
}
void TC::dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++idx, rk[idx]=x;
	if(son[x])	dfs2(son[x],tp);
	for(int y:g[x])
		if(y!=son[x]&&y!=fa[x])	dfs2(y,y);
}
int TC::query(int x){
	int ans=0;
	// DBG;
	// cout<<"###"<<x<<"###"<<endl;
	while(top[x]!=1){
		ans=max(ans,ST::query(1,1,TC::idx,dfn[top[x]],dfn[x]));
		// cout<<dfn[top[x]]<<" "<<dfn[x]<<endl;
		x=fa[top[x]];
	}
	// cout<<ans<<endl;
	return max(ans,ST::query(1,1,TC::idx,1,dfn[x]));
}

void print(int p,int l,int r){
	if(l==r)	return;
	cout<<p<<" "<<l<<" "<<r<<" "<<ST::maxx[p]<<endl;
	int mid=l+r>>1;
	print(p<<1,l,mid), print(p<<1|1,mid+1,r);
}

priority_queue<PII> q[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>c, AC::insert(c);
	AC::build();
	// cout<<endl;
	// for(int i=1;i<=AC::idx;++i){
	// 	cout<<i<<" ";
	// 	for(int j=0;j<26;++j)
	// 		cout<<AC::t[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	TC::dfs1(1,0), TC::dfs2(1,1);
	while(m--){
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			int pos=TC::dfn[AC::tag[x]];
			while(q[pos].size()&&q[pos].top().se==x)	q[pos].pop();
			q[pos].push(mk(y,x));
			ST::update(1,1,TC::idx,pos,q[pos].top().fi);
			// cout<<x<<" "<<AC::tag[x]<<" "<<TC::dfn[AC::tag[x]]<<" "<<y<<endl;
		}else{
			cin>>c;
			AC::query(c);
		}
		// for(int i=1;i<=TC::idx<<1;++i)
		// 	cout<<ST::maxx[i]<<" ";
		// cout<<endl;
		// print(1,1,TC::idx);
	}
	return 0;
}