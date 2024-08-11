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

int n,m;
int head[N],ver[M],Next[M],w[M],tot=-1;
double f[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}

void dfs(int x){
	int d=0;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(!f[y])	dfs(y);
		f[x]+=f[y]+w[i], ++d;
	}
	if(d!=0)	f[x]/=d;
}

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	dfs(1);
	printf("%.2lf\n",f[1]);
	return 0;
}
