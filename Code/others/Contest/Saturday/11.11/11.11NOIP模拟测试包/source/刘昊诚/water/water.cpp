#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define il inline
#define int long long
#define inf 0x3f3f3f3f
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f^=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();} 
	return (f?x:-x);
}
int T,n,m,h[105][105],minh=inf,sum,ans,cnt;
bool vis[105][105],book[105][105];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
void color(int idx,int idy){
	vis[idx][idy]=true;
	for(int i=1;i<=4;i++){
		int x=idx+dx[i],y=idy+dy[i];
		if(x<0||y<0||x>n+1||y>m+1||vis[x][y])continue;
		if(h[x][y]>h[idx][idy])color(x,y);
	}
	return;
}
void dfs(int idx,int idy){
	book[idx][idy]=true;
	sum+=h[idx][idy];
	++cnt;
//	printf("%d %d\n",idx,idy);
	for(int i=1;i<=4;i++){
		int x=idx+dx[i],y=idy+dy[i];
		if(x<0||y<0||x>n+1||y>m+1||book[x][y])continue;
		if(vis[x][y])minh=min(minh,h[x][y]);
	}
	for(int i=1;i<=4;i++){
		int x=idx+dx[i],y=idy+dy[i];
//		printf("%d %d\n",x,y);
		if(x<0||y<0||x>n+1||y>m+1) continue;
		if(!book[x][y]&&!vis[x][y])dfs(x,y);
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	T=read();
	while(T--){
		memset(vis,false,sizeof(vis));
		memset(book,false,sizeof(book));
		memset(h,0,sizeof(h));
		n=read(),m=read(),ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				h[i][j]=read();
		for(int i=0;i<=n+1;i++){
			color(i,0);
			color(i,m+1);
		}
		for(int i=0;i<=m+1;i++){
			color(0,i);
			color(n+1,i);
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)printf("%lld ",vis[i][j]);
//			printf("\n");
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[i][j]&&!book[i][j]){
					minh=inf,sum=cnt=0;
					dfs(i,j);
					ans+=minh*cnt-sum;
//					printf("\n");
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
3 6
3 3 4 4 4 2
3 1 3 2 1 4
7 3 1 6 4 1
*/
