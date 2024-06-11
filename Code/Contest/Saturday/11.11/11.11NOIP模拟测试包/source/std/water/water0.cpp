#include<cstdio>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N];
int s[10100];
int vis[N][N];
int T,n,m,R,L,sum;
void dfs(int x,int y,int lim){
	if(x<0||y<0||x>n+1||y>m+1)return;
	if(vis[x][y])return;
	if(a[x][y]>=lim)return;
	vis[x][y]=1;
	if(x>=1&&y>=1&&x<=n&&y<=m)sum--;
	dfs(x-1,y,lim);
	dfs(x+1,y,lim);
	dfs(x,y-1,lim);
	dfs(x,y+1,lim);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		L=1e9,R=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));//WA
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				L=min(L,a[i][j]);
				R=max(R,a[i][j]);
				s[a[i][j]]++;
			}
		for(int i=R;i>=L;i--)s[i]+=s[i+1];
		int ans=0;
		for(int i=L+1;i<=R;i++){
			memset(vis,0,sizeof(vis));
			sum=n*m-s[i];
			dfs(0,0,i);
//			if(sum==0)break;
			ans+=sum;
		}
		printf("%d\n",ans);
	}
	return 0;
}
