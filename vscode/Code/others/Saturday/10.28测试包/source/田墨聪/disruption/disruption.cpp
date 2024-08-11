#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define il inline
#define N 50005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
struct Edge {
	int from,to,w;
};
int n,m,fa[N];
Edge edge[N<<1];
il int findf(int x) {
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
il void Union(int x,int y) {
	int fx=findf(x),fy=findf(y);
	if(fx!=fy) fa[fy]=fx;
}
int main() {
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++) {
		edge[i].from=read(),edge[i].to=read();
		if(edge[i].from>edge[i].to) swap(edge[i].from,edge[i].to);
	}
	for(int i=1;i<=m;i++) {
		edge[i+50000].from=read(),edge[i+50000].to=read(),edge[i+50000].w=read();
		if(edge[i+50000].from>edge[i+50000].to) swap(edge[i+50000].from,edge[i+50000].to);
	}
	for(int i=1;i<n;i++) {
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<n;j++) if(i!=j) Union(edge[j].from,edge[j].to);
		int ans=0x3f3f3f3f;
		for(int j=1;j<=m;j++) {
			if(findf(edge[j+50000].from)!=findf(edge[j+50000].to)) ans=min(ans,edge[j+50000].w);
		}
		if(ans<0x3f3f3f3f) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}

