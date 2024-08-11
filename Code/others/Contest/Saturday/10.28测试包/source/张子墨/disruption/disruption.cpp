#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e4+5,M=1e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
struct node{
	int nx,ny,r;
}nw[N];
inline bool cmp(node a,node b){
	return a.r<b.r;
}
int n,m,x[N],y[N];
int frt[N],nxt[M],to[M],cnt;
inline void add(int u,int v){
	cnt++;
	nxt[cnt]=frt[u];
	frt[u]=cnt;
	to[cnt]=v;
	return;
}
int dep[N];
void get_dep(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=frt[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)continue;
		get_dep(v,u);
	}
	return;
}
int f[N];
bool vis[N];
void dfs(int u,int no,int rt){
	f[u]=rt;
	vis[u]=1;
	for(int i=frt[u];i;i=nxt[i]){
		int v=to[i];
		if(v==no)continue;
		if(vis[v])continue;
		dfs(v,no,rt);
	}
	return;
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++){
		x[i]=read(),y[i]=read();
		add(x[i],y[i]);add(y[i],x[i]);
	}
	for(int i=1;i<=m;i++){
		nw[i].nx=read(),nw[i].ny=read(),nw[i].r=read();
	}
	get_dep(1,0);
	sort(nw+1,nw+m+1,cmp);
	for(int i=1;i<n;i++){
		for(int i=1;i<=n;i++)vis[i]=0,f[i]=1;
//		printf("%d:\n",i);
//		printf("%d %d\n",x[i],y[i]);
		if(dep[x[i]]<dep[y[i]]){
			dfs(x[i],y[i],1);
			dfs(y[i],x[i],y[i]);
		}
		else{
			dfs(x[i],y[i],x[i]);
			dfs(y[i],x[i],1);
		}
//		for(int i=1;i<=n;i++)printf("%d ",f[i]);
//		puts("");
		for(int i=1;i<=m;i++){
			if(f[nw[i].nx]!=f[nw[i].ny]){
				printf("%d\n",nw[i].r);
				break;
			}
		}
//		puts("");
	}
	return 0;
}
