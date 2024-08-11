#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=510;
const int M=125000+10;
struct edge{
	int u,v,nxt;
}e[2*M];
int deg[N];
int u[M],v[M];
int h[N];
double E[M],a[N][N],eps=1e-8;;
int n,m,tot=0;
inline void add(int u,int v){
	e[++tot].u=u;e[tot].v=v;e[tot].nxt=h[u];h[u]=tot;
}
void gauss(){
	for(int i=1;i<=n;i++){
		int mc=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(a[j][i]>fabs(a[mc][i])))mc=j;
		if(mc!=i)
			for(int j=i;j<=n+1;j++)swap(a[i][j],a[mc][j]);
		if(fabs(a[i][i])<eps)continue;//no answer 
		for(int j=n+1;j>=i;j--)a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++){
			if(j!=i){
				double t=a[j][i];
				for(int k=i+1;k<=n+1;k++)a[j][k]-=a[i][k]*t;
			}
		}
	}
}
int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++;deg[v[i]]++;
		add(u[i],v[i]);add(v[i],u[i]);
	}
	n--;
	a[1][n+1]=-1.0;
	for(int u=1;u<=n;u++){
		a[u][u]=-1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v!=n+1)a[u][v]=1.0/deg[v];
		}
	}
	gauss();
	for(int i=1;i<=m;i++)
		E[i]=a[u[i]][n+1]/deg[u[i]]+a[v[i]][n+1]/deg[v[i]];
	sort(E+1,E+1+m);
	double ans=0;
	for(int i=1;i<=m;i++)ans+=E[i]*(m-i+1);
	printf("%.3lf\n",ans);
	return 0;
}
