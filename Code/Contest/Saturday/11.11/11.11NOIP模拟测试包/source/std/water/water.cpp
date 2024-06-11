#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};
struct Heap{
	int x,y,h;
	Heap(int xx,int yy,int hh){x=xx;y=yy;h=hh;}
	bool operator <(const Heap &t)const{return h>t.h;}
};
struct node{
	int x,y;
	node(int xx,int yy){x=xx;y=yy;}
};
const int N=110;
int a[N][N];
int inHq[N][N];
int vis[N][N];
int T,n,m,ans=0;
priority_queue<Heap>Hq;
void bfs(int xx,int yy){
	queue<node>q;
	q.push(node(xx,yy));
	vis[xx][yy]=1;
	while(!q.empty()){
		node p=q.front();q.pop();
		if(a[p.x][p.y]>a[xx][yy]){
			if(!inHq[p.x][p.y]){
				Hq.push(Heap(p.x,p.y,a[p.x][p.y]));//ÁíÍâµÄÍ° 
				inHq[p.x][p.y]=1;
			}
			continue;
		}
		for(int i=0;i<=3;i++){
			int x=p.x+dx[i],y=p.y+dy[i];
			if(x>=2&&y>=2&&x<=n-1&&y<=m-1&&!vis[x][y]){
				if(a[x][y]<=a[xx][yy])ans+=a[xx][yy]-a[x][y];
				q.push(node(x,y));
				vis[x][y]=1;
			}
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		while(!Hq.empty())Hq.pop();
		memset(vis,0,sizeof(vis));
		memset(inHq,0,sizeof(inHq));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(i==1||j==1||i==n||j==m){
					Hq.push(Heap(i,j,a[i][j]));
					inHq[i][j]=1;
				}
			}
		ans=0;
		while(!Hq.empty()){
			int x=Hq.top().x,y=Hq.top().y;Hq.pop();
			bfs(x,y);
//			printf("x:%d y:%d h:%d ans:%d\n",x,y,a[x][y],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
