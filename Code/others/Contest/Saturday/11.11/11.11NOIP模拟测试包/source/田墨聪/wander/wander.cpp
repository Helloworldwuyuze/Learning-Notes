#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define M 250000
#define N 505
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
const double eps=1e-8;
struct Edge {
	int next,u,v;
};
Edge edge[M];
int head[N],num_edge;
il void add_edge(int u,int v) {
	edge[++num_edge].next=head[u];
	edge[num_edge].u=u,edge[num_edge].v=v;
	head[u]=num_edge;
}
int n,m,d[N];
double a[N][N];
double f[M];
int main() {
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) {
		int u=read(),v=read();
		add_edge(u,v);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++) {
		a[i][i]=1;
		for(int j=head[i];j;j=edge[j].next) {
			int v=edge[j].v;
			if(v!=n) a[i][v]=-1.0/d[v];
			if(i!=n) a[v][i]=-1.0/d[i];
		}
		if(i==1) a[i][n+1]=1;
	}
	for(int i=1;i<=n;i++) {
		int id=i;
		for(int j=i+1;j<=n;j++) if(a[j][i]-a[id][i]>eps) id=j;
		if(a[id][i]<eps) /*bla bla*/;
		swap(a[i],a[id]);
		for(int j=1;j<=n;j++) {
			if(i!=j) {
				double t=a[j][i]/a[i][i];
				for(int k=1;k<=n+1;k++) a[j][k]-=t*a[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++) a[i][n+1]/=a[i][i];
	for(int i=1;i<=m;i++) {
		int u=edge[i].u,v=edge[i].v;
		if(u!=n) f[i]+=a[u][n+1]/d[u];
		if(v!=n) f[i]+=a[v][n+1]/d[v];
	}
	sort(f+1,f+m+1);
	double ans=0;
	for(int i=1;i<=m;i++) ans+=f[i]*(m-i+1);
	printf("%.3lf\n",ans);
	return 0;
}

