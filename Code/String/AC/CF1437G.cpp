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
	int maxx[N];
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
	if(l==r){ maxx[x]=k; return ;}
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
		p=(t[p][c[i]-'a'])?(t[p][c[i-'a']]):(t[p][c[i]-'a']=++idx);
	flag[p] = ++cnt, tag[cnt] = p; exist[N]=true;
}
queue<int> q;
void AC::build(){
	for(int i=0;i<26;++i)
		if(t[1][i])	q.push(t[1][i]), fail[t[1][i]]=1;
	fail[1]=1;
	while(q.size()){
		int p=q.front(); q.pop();
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
	while(top[x]!=1){
		ans=max(ans,ST::query(1,1,AC::idx,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	return max(ans,ST::query(1,1,AC::idx,1,dfn[x]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>c, AC::insert(c);
	AC::build();
	TC::dfs1(1,0), TC::dfs2(1,1);
	while(m--){
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			ST::update(1,1,AC::idx,TC::dfn[AC::tag[x]],y);
		}else{
			cin>>c;
			AC::query(c);
		}
	}
	return 0;
}