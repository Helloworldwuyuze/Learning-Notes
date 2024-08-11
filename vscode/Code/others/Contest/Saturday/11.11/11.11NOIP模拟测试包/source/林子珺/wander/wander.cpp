#include <bits/stdc++.h>
using namespace std;

const int N=510,M=125010;
const double eps=1e-10;
int n,m;
struct edge{
	int v,nxt;
}e[M*2];
int head[N],cnt=1;
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

int d[N];
double a[N][N];
double ans[M];
double sum;

int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
		d[u]++,d[v]++;
	}
	a[1][n+1]=-1;
	a[n][n]=1,a[n][n+1]=0;
	for(int i=1;i<n;i++){
		a[i][i]=-1;
		for(int j=head[i];j;j=e[j].nxt){
			a[i][e[j].v]=1.0/d[e[j].v];
		}
	}
	for(int i=1;i<=n;i++){
		int mc=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(a[j][i])>fabs(a[mc][i]))
				mc=j;
		if(mc!=i)
			for(int j=1;j<=n+1;j++)
				swap(a[i][j],a[mc][j]);
		if(fabs(a[i][i])<eps)continue;
		for(int j=n+1;j>=i+1;j--)
			a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++)
			if(j!=i)
				for(int k=i+1;k<=n+1;k++)
					a[j][k]-=a[j][i]*a[i][k];
	}
	
	for(int i=1;i<=m;i++){
		int u=e[i*2].v;
		int v=e[i*2-1].v;
		ans[i]=a[u][n+1]/d[u]+a[v][n+1]/d[v];
	}
	sort(ans+1,ans+1+m,greater<double>());
	for(int i=1;i<=m;i++)sum+=ans[i]*i;
	printf("%.3lf\n",sum);
	return 0;
}
