#include<iostream>
#include<cstdio>
#include<vector>
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
vector<int>G[50005],I[50005]; 
int dfn[50005],siz[50005],top[50005];
int dyd[50005],dep[50005],hson[50005],f[50005];
int ans[50005];int n,m;
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=0; i<G[x].size(); i++){
		int y=G[x][i];
		if(y==fa){continue;}
		dyd[y]=I[x][i];
		dep[y]=dep[x]+1;
		f[y]=x;
		dfs(y,x);
		siz[x]+=siz[y];		
		if(siz[hson[x]]<siz[y])hson[x]=y;
	}
}void dfs2(int x,int fa,int t){
	dfn[x]=++dfn[0];
	if(!hson[x]){return;}
	top[hson[x]]=t;
	dfs2(hson[x],x,t);
	for(int i=0 ; i<G[x].size() ;i++){
		int y=G[x][i];
		if(y==fa||y==hson[x]){continue;}
		top[y]=y;
		dfs2(y,x,y);
	}
}int tr[50005<<4];
int lazy[50005<<4];
void pushup(int rt){
	tr[rt]=min(min(tr[rt],tr[lson]),tr[rson]);
}void build(int rt,int l,int r){
	int mid=(l+r)>>1;
	if(l==r){
		tr[rt]=1000000000;
		return;
	}build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}void pushdown(int rt){
//	cout<<114514<<endl;
	if(lazy[rt]!=1000000000){
		int k=lazy[rt];
		tr[lson]=min(tr[lson],k);
		lazy[lson]=min(lazy[lson],k);
		tr[rson]=min(tr[rson],k);
		lazy[rson]=min(lazy[rson],k);
		lazy[rt]=1000000000;
	}
}
void update(int rt,int l,int r,int x,int y,int k){
	if(l>y||r<x){return;}
	if(x<=l&&r<=y){tr[rt]=min(tr[rt],k);lazy[rt]=min(lazy[rt],k);return;}
	int mid=(l+r)>>1;
	pushdown(rt);
	update(lson,l,mid,x,y,k);
	update(rson,mid+1,r,x,y,k);
	pushup(rt);
}int query(int rt,int l,int r,int x){
	if(l==r){return tr[rt];}
	int mid=(l+r)>>1;
	pushdown(rt);
	if(x<=mid){return query(lson,l,mid,x);}
	else {return query(rson,mid+1,r,x);}
}void update_path(int x,int y,int k){
	while(top[x]!=top[y]){
		int tx=top[x],ty=top[y];
		if(dep[tx]>dep[ty]){
			update(1,1,n,dfn[tx],dfn[x],k);
			x=f[tx];
		}else{
			update(1,1,n,dfn[ty],dfn[y],k);
			y=f[ty];
		}
	}if(dep[x]>dep[y]){swap(x,y);}
	update(1,1,n,dfn[x]+1,dfn[y],k);
	return;
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<n ;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		I[x].push_back(i);
		I[y].push_back(i);
	}dfs(1,-1);
	top[1]=1;
	dfs2(1,-1,1);
	for(int i=1; i<=200000; i++)tr[i]=1000000000,lazy[i]=1000000000;
//	build(1,1,n);
	for(int i=1; i<=m; i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		update_path(x,y,z);
	}
//	for(int i=206; i<=n; i++){
//		printf("%d\n",query(1,1,n,i));
//	}//cout<<endl;
	for(int i=2; i<=n ;i++){
//		cout<<dyd[i]<<endl;
		ans[dyd[i]]=query(1,1,n,dfn[i]);
		
	}
	for(int i=1; i<n; i++){
		if(ans[i]==1000000000)printf("-1\n");
		else printf("%d\n",ans[i]);
	}
	return 0;
}/*
13 2
1 2
1 3
1 7
2 4
2 5
2 6
7 8
7 9
8 10
8 11
10 12
12 13
9 11 2
13 6 1

*/
