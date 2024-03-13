#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<vector>

using namespace std;

const int N = 500 + 10;
const int M = N*N + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int Next[M],ver[M],head[N],tot=-1;
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
} 
int n,m,d[N],x[M],y[M];
double a[N][N],f[M];

void Gauss(){
	for(int i=1;i<n;++i){
		int idx=i;
		for(int j=i+1;j<n;++j)
			if(fabs(a[j][i])>fabs(a[idx][i]))	idx=j;
		if(idx!=i)
			for(int j=1;j<=n;++j)	swap(a[i][j],a[idx][j]);
		for(int j=n;j>=i;--j)	a[i][j]/=a[i][i];
		for(int j=1;j<=n;++j){
			if(j==i)	continue;
			double t=a[j][i];
			for(int k=i;k<=n;++k)	a[j][k]-=t*a[i][k];
		}
	}
}

int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	scanf("%d%d",&n,&m); memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]), add(y[i],x[i]);
		d[x[i]]++,d[y[i]]++;
	}
	for(int i=head[1];~i;i=Next[i]){
		int y=ver[i];
		a[1][y]=1.0/d[y];
	}
	a[1][1]=a[1][n]=-1;
	for(int i=2;i<=n;++i){
		a[i][i]=-1;
		for(int j=head[i];~j;j=Next[j]){
			int y=ver[j];
			a[i][y]=1.0/d[y];
		}
		a[i][n]=0;
	}
	Gauss();
	a[n][n]=0;
	for(int i=1;i<=m;++i){
//		cout<<x[i]<<" "<<y[i]<<endl;
	}
	for(int i=1;i<=m;++i){
//		cout<<d[x[i]]<<" "<<y[i]<<endl;
		f[i]=a[x[i]][n]/d[x[i]]+a[y[i]][n]/d[y[i]];
	}
//	cout<<"QAQ"<<endl;
	sort(f+1,f+1+m);
	double ans=0;
	for(int i=1;i<=m;++i)
		ans+=f[i]*(m-i+1);
	printf("%.3lf",ans);
	return 0;
}

