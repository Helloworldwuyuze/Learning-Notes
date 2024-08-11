#include<bits/stdc++.h>

using namespace std;

const int N = 500 + 10;
const int M = 125000 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m;
struct edge{
	int x,y;
	double e;
}e[M];
int d[N];
double a[N][N],f[N],fe[N];
int Next[M<<1],ver[M<<1],head[N],tot=-1;
void add(int x,int y){ ver[++tot]=y; Next[tot]=head[x]; head[x]=tot;}

void Gauss(){
	for(int i=1;i<n;++i){
//		cout<<endl<<"###"<<i<<"###"<<endl;
		int pos=i;
		for(int j=i+1;j<n;++j)
			if(fabs(a[j][i])>fabs(a[pos][i]))	pos=j;
		if(pos!=i)
			for(int j=1;j<=n;++j)	swap(a[i][j],a[pos][j]);
		for(int j=n;j>=i;--j)	a[i][j]/=a[i][i];
		for(int j=1;j<n;++j){
			if(j==i)	continue;
			double t=a[j][i];
//			cout<<"ERR"<<a[j][i]<<" "<<t<<" "<<a[i][i]<<endl;
			for(int k=i;k<=n;++k)	a[j][k]-=t*a[i][k];
		}
//		for(int i=1;i<n;++i,cout<<endl)
//			for(int j=1;j<=n;++j)	printf("%.3lf ",a[i][j]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		cin>>e[i].x>>e[i].y;
		add(e[i].x, e[i].y), add(e[i].y, e[i].x);
		d[e[i].x]++, d[e[i].y]++;
	}
	for(int i=head[1];~i;i=Next[i])
		a[1][ver[i]]=1.0/d[ver[i]];
	a[1][1]=a[1][n]=-1;
	for(int i=2;i<n;++i){
		a[i][i]=-1;
		for(int j=head[i];~j;j=Next[j])
			a[i][ver[j]]=1.0/d[ver[j]];
		a[i][n]=0;
	}
	Gauss();
//	for(int i=1;i<n;++i,cout<<endl)
//		for(int j=1;j<=n;++j)	printf("%.3lf ",a[i][j]);
	for(int i=1;i<n;++i)	f[i]=a[i][n];
	for(int i=1;i<=m;++i){
		fe[i]=f[e[i].x]/d[e[i].x]+f[e[i].y]/d[e[i].y];
	}
	sort(fe+1,fe+1+m);
	double ans;
	for(int i=1;i<=m;++i)	ans+=fe[i]*(m-i+1);
	printf("%.3lf\n",ans);
	return 0;
}

