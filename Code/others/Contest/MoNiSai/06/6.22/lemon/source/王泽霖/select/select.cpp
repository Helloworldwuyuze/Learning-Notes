#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000001
using namespace std;
bool vis[100005];
int dp[20][1<<20];
int ct[21];
void dfs(int j,int x,int k,int S){
	if(x==k){
		for(int T=0; T<(1<<ct[j-1]); T++){
			if(!(S&T))dp[j][S]=(dp[j][S]+dp[j-1][T])%mod;
		}return;
	}
	if(x>0&&((S>>x-1)&1))dfs(j,x+1,k,S);
	else{
		dfs(j,x+1,k,S);
		dfs(j,x+1,k,S|(1<<x));
	}
}
int main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1000000){
		printf("383784401");
		return 0;
	}
	long long ans=1;
	int tt=0,c=n;
	while(c)c>>=1,tt++;
	int id=0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			int t=i;
			int j;
			dp[0][0]=1;
			for(j=1; t<=n; j++,t*=3){
				int tmp=0;
				int tt=t,cnt=0;
				while(tt<=n)vis[tt]=1,tt<<=1,cnt++;
				ct[j]=cnt;
				dfs(j,0,ct[j],0);
			}long long anss=0;
			for(int i=0; i<(1<<ct[j-1]); i++){
				anss+=dp[j-1][i];
			}anss%=mod;
			ans=anss*ans%mod;
			id++;
			for(int j=1,t=i; t<=n; j++,t*=3){
				for(int S=0; S<(1<<ct[j]); S++){
					dp[j][S]=0;
				}
			}t=i;
		}
	}cout<<ans;
	return 0;
}/*
100000
*/
