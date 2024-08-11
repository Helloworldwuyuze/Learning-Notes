#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define F(i,x,y) for(int i=(x);i<=(y);++i)
#define Fo(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
int n;
struct edge{
	int v,next,w;
}e[N<<1];
int head[N],tot;
void add(int u,int v,int w){
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}
int dis[N*32],cnt,ans;
int t[N*32][2];
void dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dis[v]=dis[u]^e[i].w;
		dfs(v,u);
	}
}
void insert(int x){
	int p=1;
	Fo(i,30,0){
		int c=(x>>i)&1;
		if(!t[p][c]) t[p][c]=++cnt;
		p=t[p][c];
	}
}
int query(int x){
	int p=1,tmp=0;
	Fo(i,30,0){
		int c=(x>>i)&1;
		if(t[p][c^1]){
			tmp=tmp*2+(c^1);
			p=t[p][c^1];
		}
		else{
			tmp=tmp*2+c;
			p=t[p][c];
		}
	}
	return tmp^x;
}
signed main(){
	while(scanf("%d",&n)!=EOF){
		F(i,1,n) head[i]=0;
		F(i,1,n*32) dis[i]=0,t[i][0]=t[i][1]=0;
		tot=ans=0;
		cnt=1;
		int x,y,z;
		F(i,1,n-1){
			scanf("%d%d%d",&x,&y,&z);
			x++,y++;
			add(x,y,z);
			add(y,x,z);
		}
		dfs(1,0);
		F(i,1,n) insert(dis[i]);
		F(i,1,n) ans=max(ans,query(dis[i]));
		printf("%d\n",ans);
	}
	return 0;
}