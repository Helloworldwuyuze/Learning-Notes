#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=310;
const int M=50010;
typedef long long ll;
int n,m;
struct node{
	ll w,l,r,len;
}c[M];
bool cmp(node a,node b){
	if(a.len<b.len) return true;
	return false;
}
ll dp[M];
int et[M][N];
bool check(int x,int y){
	for(int i=1;i<=n;i++){
		if(et[x][i]==1&&et[y][i]==0){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&c[i].w,&c[i].l,&c[i].r);
		c[i].len=c[i].r-c[i].l+1;
	}
	sort(c+1,c+1+m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=c[i].l;j<=c[i].r;j++){
			et[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++){
			if(check(i,j)){
				dp[i]=max(dp[i],dp[j]+c[i].w);
			}
		}
	}
	ll maxx=0;
	for(int i=1;i<=m;i++){
		maxx=max(maxx,dp[i]);
	}
	printf("%lld\n",maxx);
	return 0;
}
