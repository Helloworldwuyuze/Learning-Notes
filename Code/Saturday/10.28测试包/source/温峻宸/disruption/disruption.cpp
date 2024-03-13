#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m,k,a[N],b[N],c[N],u,v,d[N],e[N],q[N];
int tot,h[N],to[M],nxt[M];
void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=h[u];
	h[u]=tot;
} 
void dfs(int u,int fu){
	q[u]=1;
	for(int i=h[u];i;i=nxt[i])if(to[i]!=fu)dfs(to[i],u);
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&d[i],&e[i]);
		add(d[i],e[i]);add(e[i],d[i]);
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<n;i++){
		memset(q,0,sizeof q);
		dfs(d[i],e[i]);
		int ans=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			if(q[a[i]]+q[b[i]]==1)ans=min(ans,c[i]);
		}
		//if(i==3)for(int i=1;i<=n;i++)printf("%d ",q[i]);
		printf("%d\n",ans==0x3f3f3f3f?-1:ans);
	}
	
	return 0;
}

