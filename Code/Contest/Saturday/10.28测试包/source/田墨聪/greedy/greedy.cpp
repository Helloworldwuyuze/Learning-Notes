#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define il inline
#define N 305
#define M 90005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
struct node {
	int l,r,w;
};
int n,m;
int l[M],r[M],w[M];
int dp[N][N],maxn[N][N][N];
node a[M];
signed main() {
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) {
		w[i]=read(),l[i]=read(),r[i]=read();
		a[i].l=l[i],a[i].r=r[i],a[i].w=w[i];
	}
	for(int i=1;i<=m;i++) {
		for(int j=a[i].l;j<=a[i].r;j++) {
			for(int k=1;k<=a[i].l;k++) for(int l=a[i].r;l<=n;l++) maxn[k][l][j]=max(maxn[k][l][j],a[i].w);
		}
	}//very slow.
	for(int len=1;len<=n;len++) {
		for(int i=1;i+len-1<=n;i++) {
			int j=i+len-1;
			for(int k=i;k<j;k++) dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			for(int k=i;k<=j;k++) dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+maxn[i][j][k]);
		}
	}//very fast.
	printf("%d\n",dp[1][n]);
	return 0;
}

