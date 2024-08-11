#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n,m,od[N];
int head[N],ver[M],Next[M],w[M],tot=-1;
double f[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}

void dfs(int x,double p){
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		f[y]+=f[x]+p*w[i];
		if(od[y]!=0)	dfs(y,p/od[y]);
		else	dfs(y,p);
	}
	cout<<x<<" "<<f[x]<<endl;
}

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		od[x]++;
		add(x,y,z);
	}
	dfs(1,1.0/od[1]);
	printf("%.2lf\n",f[n]);
	return 0;
}

