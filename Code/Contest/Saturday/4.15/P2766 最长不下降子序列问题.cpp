#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, M = 6e5 + 10, INF = 0x3f3f3f3f;
int n,m,head[N],ver[M<<1],Next[M<<1],w[M<<1],tot=-1,a[N],f[N],de[N],cur[N],Maxs,Maxnum;
bool vis[N];
void add(int x,int y,int z){ ver[++tot]=y; w[tot]=z; Next[tot]=head[x]; head[x]=tot; }
bool bfs(){
	queue<int> q;
	memset(de,-1,sizeof(de));
	de[0]=0, q.push(0);
	while(q.size()){
		int x=q.front(); q.pop();
		for(int i=head[x];~i;i=Next[i])
			if(w[i]&&de[ver[i]]==-1)	q.push(ver[i]), de[ver[i]]=de[x]+1;
	}
	return de[2*n+1]!=-1;
}
int dfs(int x,int minf){
	if(x==2*n+1||minf==0)	return minf;
	int f,flow=0;
	for(int i=cur[x];~i;i=Next[i]){
		cur[x]=i;
		int y=ver[i],z=w[i];
		if(de[y]==de[x]+1&&(f=dfs(y,min(minf,z)))){
			minf-=f, flow+=f;
			w[i]-=f, w[i^1]+=f;
			if(minf==0)	return flow;
		}
	}
	return flow;
}
int Dinic(){
	int Maxflow=0;
	while(bfs()){	for(int i=0;i<=n*2+1;++i)	cur[i]=head[i]; Maxflow+=dfs(0,INF); }
	return Maxflow;
}
signed main(){
	cin>>n;
	if(n==1){ cout<<1<<endl<<1<<endl<<1<<endl; return 0; }
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;++i)	cin>>a[i];
	f[1]=1;
	for(int i=2;i<=n;++i){
		int F=0;
		for(int j=1;j<i;++j)
			if(a[j]<=a[i]&&f[j]>F)	F=f[j];
		f[i]=F+1;
	}
	for(int i=1;i<=n;++i)	Maxs=max(Maxs,f[i]);
	cout<<Maxs<<endl;
	for(int i=1;i<=n;++i){
		add(i,i+n,1), add(i+n,i,0);
		if(f[i]==1)	add(0,i,1), add(i,0,0);
		if(f[i]==Maxs)	add(i+n,2*n+1,1), add(2*n+1,i+n,0);
		for(int j=i-1;j;--j)
			if(a[i]>=a[j]&&f[i]==f[j]+1)	add(i,j+n,0), add(j+n,i,1);
	}
	cout<<(Maxnum=Dinic())<<endl;
	add(1,n+1,INF), add(n+1,1,INF), add(0,1,INF), add(1,0,INF), add(n,2*n,INF), add(2*n,n,INF);
	if(f[n]==Maxs)	add(2*n,2*n+1,INF), add(2*n+1,2*n,INF);
	cout<<Maxnum+Dinic()<<endl;
	return 0;
}
