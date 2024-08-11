#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define mod 98244353
#define inf 0x3f3f3f3f
#define N 100005
using namespace std;
int t,n,m,a[105][105],vis[105][105],maxx,ans;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int bfs(int x,int y,int h){
	bool flag=0;
	int sum=1;
	vis[x][y]=1;
	queue<int> qx,qy;
	qx.push(x);
	qy.push(y);
	while(!qx.empty()){
		int X=qx.front();
		int Y=qy.front();
		qx.pop();
		qy.pop();
		for(int i=1;i<=4;i++){
			int xx=X+dx[i];
			int yy=Y+dy[i];
			//cout<<xx<<" "<<yy<<endl;
			if(xx<1||xx>n||yy<1||yy>m){
				flag=1;
				continue;
			}
			if(vis[xx][yy]==1){
				continue;
			}
			if(a[xx][yy]>=h){
				continue;
			}
			sum++;
			qx.push(xx);
			qy.push(yy);
			vis[xx][yy]=1;
		}
	}
	if(flag==1){
		return 0;
	}
	else{
		return sum;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d %d",&n,&m);
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				maxx=max(maxx,a[i][j]);
			}
		}
		for(int k=2;k<=maxx;k++){
			memset(vis,0,sizeof vis);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(a[i][j]<k&&vis[i][j]==0){
						ans=ans+bfs(i,j,k);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
