#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50005;
int n,m,tot=0,h[N],res[N],tot1=0,d[N],fa[N][20],f[N],g[N];
struct edge{
	int u,v,nxt,id;
}e[N*2];
struct eg{
	int u,v,w;
}e1[N*2];
void add(int u,int v,int id){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].id=id;
	e[tot].nxt=h[u];
	h[u]=tot;
}
bool cmp(eg a,eg b){
	return a.w<b.w;
}
void dfs(int u,int p){
	d[u]=d[p]+1;
	fa[u][0]=p;
	for(int i=1;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==p)continue;
		g[v]=i;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(d[fa[x][i]]>=d[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(res,-1,sizeof(res));
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i);
		add(v,u,i);
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e1[++tot1]=(eg){u,v,w};
	}
	sort(e1+1,e1+m+1,cmp);
	dfs(1,0);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int w=e1[i].w;
		int l=lca(e1[i].u,e1[i].v);
		for(int j=find(e1[i].u);d[j]>d[l];j=find(j)){
			if(f[j]!=j)continue;
			res[e[g[j]].id]=w;
			f[j]=find(fa[j][0]);
		}
		for(int j=find(e1[i].v);d[j]>d[l];j=find(j)){
			if(f[j]!=j)continue;
			res[e[g[j]].id]=w;
			f[j]=find(fa[j][0]);
		}
	}
	for(int i=1;i<n;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}
