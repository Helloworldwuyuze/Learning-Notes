#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define N 50005
#define il inline
#define ll long long
#define inf 0x3f3f3f3f
typedef pair<ll,int> pii;
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,h[N],tot;
ll d[N];
bool vis[N];
struct edge{
	int u,v,w,nxt;
}e[N<<2];
il void add(int u,int v,int w){
	e[++tot].v=v,e[tot].u=u,e[tot].w=w;
	e[tot].nxt=h[u],h[u]=tot;
}
struct Q{
	int u,v;
}a[N];
il bool chk(int i,int s,int t){
	if(e[i].w!=0)return true;
	int u=e[i].u,v=e[i].v;
	if(u==s&&v==t)return false;
	if(u==t&&v==s)return false;
	return true;
}
il void Dijkstra(int s,int t){
	priority_queue<pii> q;
	memset(d,inf,sizeof(d));
	memset(vis,false,sizeof(vis));
	d[s]=0,vis[s]=true;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pii p=q.top();q.pop();
		int u=p.second;ll dst=p.first;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(!chk(i,s,t))continue;
			if(d[v]>d[u]+w){
				d[v]=(long long)d[u]+w;
				q.push(make_pair(-d[v],v));
			}
		}
	}
} 
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++){
		a[i].u=read(),a[i].v=read();
		add(a[i].u,a[i].v,0);
		add(a[i].v,a[i].u,0);
	}
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<n;i++){
		int s=a[i].u,t=a[i].v;
		Dijkstra(s,t);
		printf("%lld\n",d[t]);
	}
	return 0;
}
