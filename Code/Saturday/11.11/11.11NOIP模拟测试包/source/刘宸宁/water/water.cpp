/*
1
3 6 
3 3 4 4 4 2 
3 1 3 2 1 4 
7 3 1 6 4 1
*/
#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;
typedef int ll;
ll t,n,m,mp[105][105],vis[105][105];
ll dx[5]={0,-1,0,1,0};
ll dy[5]={0,0,1,0,-1};
ll sum=0,minn=INF,maxx=-INF;
struct node{
	ll ai,xi,yi;
}b[30005];
ll cnt,flag;
ll dfs(ll x,ll y){
	vis[x][y]=1;
	maxx=max(maxx,mp[x][y]);
	ll wate_ans=0;
	for(ll i=1;i<=4;i++){
		
		ll px=x+dx[i],py=y+dy[i];
//		if(flag) printf("114514 %d %d %d %d\n",px,py,mp[px][py],minn);
//		if(x==2&&y==5) printf("1145 %d %d %d\n",px,py,vis[px][py]);
		if(px<1||px>n||py<1||py>m||vis[px][py]) continue;
//		if(x==2&&y==5) printf("11456\n");
		if(px==1||px==n||py==1||py==m){minn=min(minn,(mp[px][py] <= maxx ? -1 : mp[px][py]));continue;} 
		if(mp[px][py]<=maxx){
			
			ll p=mp[px][py];
			ll op=dfs(px,py);
			if(op == -1){return -1;}
			b[++cnt].ai=mp[px][py];
			b[cnt].xi=px,b[cnt].yi=py;
		}
		else{
			minn=min(minn,(mp[px][py] <= maxx ? -1 : mp[px][py]));continue;
//			if(minn==-1) printf("19198 %d %d\n",px,py);
		}		
	}
	return minn;
}
void debug(){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				printf("%d ",mp[i][j]);
			}
			pr;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;maxx=-INF;minn=INF;
		scanf("%d%d",&n,&m);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
				scanf("%d",&mp[i][j]);
		for(ll i=2;i<n;i++){
			for(ll j=2;j<m;j++){
				maxx=-INF;minn=INF;cnt=0;
				memset(vis,0,sizeof(vis));
//				if(i==2&&j==4) flag=1,debug();
//				if(i==2&&j==5){
//					for(ll i=1;i<=n;i++){for(ll j=1;j<=m;j++){printf("%d ",mp[i][j]);}pr;}
//				}
				ll o=dfs(i,j);
//				if(i==2&&j==4) flag=0;
				if(o == -1) continue;
				sum+=minn - mp[i][j],mp[i][j]=o;
				for(ll i=1;i<=cnt;i++) sum += minn - b[i].ai,mp[b[i].xi][b[i].yi]=o;
//				printf("%d %d %d %d\n",i,j,sum,o);
				
			}
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
