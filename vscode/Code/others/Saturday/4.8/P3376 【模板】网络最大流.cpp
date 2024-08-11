#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long

using namespace std;

const int N = 2e2 + 10;
const int M = 5e3 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,m,s,t;
int head[N],ver[M<<1],Next[M<<1],w[M<<1],tot=-1;
int Maxflow;
bool vis[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}

int dfs(int x,int minf){
	if(x==t||minf==0)	return minf;
	vis[x]=true;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		int z=w[i];
		if(z==0||vis[y])	continue;
		int f=dfs(y,min(minf,z));
		if(f>0){
			w[i]-=f, w[i^1]+=f;
			return f;
		}
	}
	return 0;
}

void FF(){
	Maxflow=0;
	while(1){
		memset(vis,false,sizeof(vis));
		int f=dfs(s,INF);
		if(f==0)	return ;
		Maxflow+=f;
	}
}

signed main(){
	cin.tie(0); cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z), add(y,x,0);
	}
	FF();
	cout<<Maxflow<<endl;
	return 0;
} 
