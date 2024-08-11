#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long

using namespace std;
const int N = 200 + 10;
const int M = 5e3 + 10; 
const int INF = 0x3f3f3f3f3f3f3f3f;
#define endl '\n'
int n,m,s,t;
int nxt[M<<1],head[N],ver[M<<1],w[M<<1],tot=-1;
bool vis[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

int dfs(int x,int minf){
	if(x==t)	return minf;
	vis[x]=true;
	for(int i=head[x];~i;i=nxt[i]){
		int y=ver[i];
		int z=w[i];
		if(z&&!vis[y]){
			int f=dfs(y,min(minf,z));
			if(f){
				w[i]-=f, w[i^1]+=f;
				return f;
			}
		}
	}
	return 0;
}

int FF(){
	int Maxflow=0;
	while(1){
		memset(vis,false,sizeof vis);
		int f=dfs(s,INF);
		if(f==0)	return Maxflow;
		Maxflow+=f;
	}
}

signed main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s>>t;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z), add(y,x,0);
	}
	cout<<FF()<<endl;
	return 0;
}
