#include<iostream>
#include<cstdio>
using namespace std;
inline int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
const int N=100005;
int n,q,a[N],head[N],tot,ans[N];
struct edge{
	int v,nxt;
}e[N<<1];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int fa[N],dep[N],siz[N],hson[N],dfn[N],Time,top[N];
void dfs1(int u,int fath)
{
	fa[u]=fath,dep[u]=dep[fath]+1,siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fath)continue;
		dfs1(v,u);siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]])hson[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++Time;
	if(hson[u])dfs2(hson[u],tp);
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].v!=fa[u]&&e[i].v!=hson[u])dfs2(e[i].v,e[i].v);
}
inline int LCA(int x,int y)
{
	while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y); x=fa[top[x]];}
	return dep[x]>dep[y]?y:x;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs1(1,0);dfs2(1,1);
	for(int i=1;i<=q;i++)
	{
		int u,k,res=0;cin>>u>>k;
		for(int v=1;v<=n;v++)
		{
			int lca=LCA(u,v);
			int dis=dep[u]-dep[lca]+dep[v]-dep[lca];
			if(dis==k)ans[i]+=a[v];
		}
	}
	if(q>10000)
	{
		int res=0;
		for(int i=1;i<=q;i++)res^=i*ans[i];
		printf("%d\n",res);
	}
	else
	{
		for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
