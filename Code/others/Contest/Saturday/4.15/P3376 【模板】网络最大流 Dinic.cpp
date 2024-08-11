#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
#define endl '\n'

using namespace std;
const int N = 200 + 10;
const int M = 5e3 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,m,s,t;
int head[N],ver[M<<1],nxt[M<<1],w[M<<1],tot=-1;
int de[N],cur[N];

void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

bool bfs(){
	queue<int> q;
	q.push(s);
	memset(de,-1,sizeof(de));
	de[s]=0;
	while(q.size()){
		int x=q.front(); q.pop();
		for(int i=head[x];~i;i=nxt[i]){
			int y=ver[i];
			int z=w[i];
			if(de[y]==-1&&z){
				q.push(y);
				de[y]=de[x]+1;
			}
		}
	}
	return de[t]!=-1;
}

int dfs(int x,int minf){
	if(x==t||minf==0)	return minf;
	int flow=0;
	for(int i=cur[x];~i;i=nxt[i]){
		cur[x]=i;
		int y=ver[i];
		int z=w[i];
		if(de[y]==de[x]+1&&z){
			int f=dfs(y,min(minf,z));
			flow+=f, minf-=f;
			w[i]-=f, w[i^1]+=f;
			if(minf==0)	return flow;
		}
	}
	return flow;
}

int Dinic(){
	int Maxflow=0;
	while(bfs()){
		for(int i=1;i<=n;++i)	cur[i]=head[i];
		Maxflow+=dfs(s,INF);
	}
	return Maxflow;
}

signed main(){
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s>>t;
	memset(head,-1,sizeof head);
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z), add(y,x,0);
	}
	cout<<Dinic()<<endl;
	return 0;
}
