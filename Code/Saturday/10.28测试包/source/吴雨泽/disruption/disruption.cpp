#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<stack>

using namespace std;

const int N = 5e4 + 10;
const int M = 1e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

namespace tree{
	struct node{
		int left,right,minn,tag;
	}t[N<<2];
	void build(int p,int left,int right){
		t[p].left=left, t[p].right=right; t[p].minn=INF, t[p].tag=INF;
		if(left==right)	return ;
		int mid=left+right>>1;
		build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	}
	void push_up(int p){
		t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
	}
	void push_down(int p){
		if(t[p].tag==INF)	return ;
		t[p<<1].tag=min(t[p<<1].tag, t[p].tag), t[p<<1|1].tag=min(t[p<<1|1].tag,t[p].tag);
		t[p<<1].minn=min(t[p<<1].minn, t[p].tag), t[p<<1|1].minn=min(t[p<<1|1].minn,t[p].tag);
		t[p].tag=INF;
	}
	void update(int p,int left,int right,int k){
		if(left<=t[p].left&&t[p].right<=right){
			t[p].minn=min(t[p].minn,k);
			t[p].tag=min(t[p].tag,k);
			return ;
		}
		push_down(p);
		int mid=t[p].left+t[p].right>>1;
		if(left<=mid)	update(p<<1,left,right,k);
		if(right>mid)	update(p<<1|1,left,right,k);
		push_up(p);
	}
	int query(int p,int x){
		if(t[p].left==t[p].right)	return t[p].minn;
		push_down(p);
		int mid=t[p].left+t[p].right>>1;
		if(x<=mid)	return query(p<<1,x);
		else	return query(p<<1|1,x);
	}
}

int n,m,t,u[N],v[N];
int head[N],ver[M],Next[M],tot=-1;
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}

int son[N],dep[N],fa[N][20],top[N],rk[N],dfn[N],siz[N],idx;

void dfs1(int x,int fat){
	dep[x]=dep[fat]+1, fa[x][0]=fat; siz[x]=1;
	for(int i=1;i<=t;++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fat)	continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])	son[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++idx; rk[idx]=x;
	if(son[x])	dfs2(son[x],tp);
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x][0]||y==son[x])	continue;
		dfs2(y,y);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	for(int i=t;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y])	x=fa[x][i];
	if(x==y)	return x;
	for(int i=t;i>=0;--i)
		if(fa[x][i]!=fa[y][i])	x=fa[x][i], y=fa[y][i];
	return fa[x][0];
}

void update(int x,int y,int z){
	while(top[x]!=top[y]){
		tree::update(1,dfn[top[x]],dfn[x],z);
		x=fa[top[x]][0];
	}
	if(x==y)	return ;
	tree::update(1,dfn[y]+1,dfn[x],z);
}

int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	t=log(n)/log(2)+1; 
	for(int i=1,x,y;i<n;++i)	cin>>u[i]>>v[i], add(u[i],v[i]), add(v[i],u[i]);
	dfs1(1,0); dfs2(1,1);
	
//	for(int i=1;i<=n;++i,cout<<endl)
//		for(int j=0;j<=t;++j)	cout<<fa[i][j]<<" ";

	tree::build(1,1,n);
	for(int i=1,x,y,z;i<=m;++i){
		cin>>x>>y>>z;
		int lca=LCA(x,y);
//		cout<<lca<<endl;
		update(x,lca,z);
		update(y,lca,z);
//		for(int j=1;j<=n<<2;++j)
//			cout<<j<<" "<<tree::t[j].left<<" "<<tree::t[j].right<<" "<<tree::t[j].minn<<" "<<tree::t[j].tag<<endl;
//		cout<<endl;
	}
	for(int i=1;i<n;++i){
		if(fa[u[i]][0]==v[i]){
			int ans=tree::query(1,dfn[u[i]]);
			if(ans==INF)	cout<<-1<<endl;
			else	cout<<ans<<endl;;
		}else{
			int ans=tree::query(1,dfn[v[i]]);
			if(ans==INF)	cout<<-1<<endl;
			else	cout<<ans<<endl;
		}
	}
	return 0;
}
/*
6 3 
1 2 
1 3 
4 1 
4 5 
6 5 
2 3 7 
3 6 8 
6 4 5
*/
