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
int Next[M<<1],ver[M<<1],head[N],w[M<<1],tot=-1;
bool vis[N];
int Flow[N],pre[N];

inline void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}

int bfs(){
	queue<int> q;
	memset(vis,false,sizeof(vis));
	memset(pre,0,sizeof(pre));
	q.push(s), vis[s]=true, Flow[s]=INF;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=head[x];~i;i=Next[i]){
			int y=ver[i];
			int z=w[i];
			if(z==0||vis[y])	continue;
			Flow[y]=min(Flow[x],z);
			pre[y]=i, vis[y]=true, q.push(y);
			if(y==t)	return Flow[y];
		}
	}
	return 0;
}

void EK(){
	int f=0;
	while(f=bfs()){
		Maxflow+=f;
		int x=t;
		while(x!=s){
			int i=pre[x];
			w[i]-=f, w[i^1]+=f;
			x=ver[i^1];
		}
	}
}

signed main(){
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s>>t;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z), add(y,x,0);
	}
	EK();
	cout<<Maxflow<<endl;
	return 0;
}
