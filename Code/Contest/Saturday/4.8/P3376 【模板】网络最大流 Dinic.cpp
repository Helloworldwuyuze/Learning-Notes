#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define int long long

using namespace std;
const int N = 2e2 + 10;
const int M = 5e3 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f; 
int n,m,s,t,Maxflow;
int Next[M<<1],ver[M<<1],w[M<<1],head[N],tot=-1;
int cur[N],d[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}

bool bfs(){
	queue<int> q;
	memset(d,-1,sizeof(d));
	q.push(s), d[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=head[x];~i;i=Next[i]){
			int y=ver[i];
			int z=w[i];
			if(d[y]!=-1||z==0)	continue;
			q.push(y);
			d[y]=d[x]+1;
		}
	}
	return d[t]!=-1;
}

int dfs(int x,int minf){
	if(x==t||minf==0)	return minf;
	int f,flow=0;
	for(int i=cur[x];~i;i=Next[i]){
		cur[x]=i;
		int y=ver[i];
		int z=w[i];
		if(d[y]!=d[x]+1||(f=dfs(y,min(minf,z)))==0)	continue;
		minf-=f, flow+=f;
		w[i]-=f, w[i^1]+=f;
		if(minf==0)	return flow;
	}
	return flow;
}

void Dinic(){
	Maxflow=0;
	while(bfs()){
		for(int i=1;i<=n;++i)	cur[i]=head[i];
		Maxflow+=dfs(s,INF);
	}
	return ;
}

signed main(){
	memset(head,-1,sizeof(head));
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z), add(y,x,0); 
	}
	Dinic();
	cout<<Maxflow<<endl;
	return 0;
} 
