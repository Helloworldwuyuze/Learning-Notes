#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define mod 1000000001
#define N 1000005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
ll n,ans=1;
ll len[15],dp[15][1<<20];
bool vis[N],g[1<<20];
vector<int> S[21]; 
il ll solve(int m) {
	ll rw=0;
	for(int i=m;i<=n;i*=3) {
		rw++;
		for(int j=i;j<=n;j*=2) len[rw]++,vis[j]=1;
	}
	for(int i=0;i<(1<<len[1]);i++) {
		if(g[i]) dp[1][i]=1;
		else dp[1][i]=0;
	}
	for(int i=2;i<=rw;i++) {
		for(auto s:S[len[i]-1]) {
			dp[i][s]=0;
			for(auto t:S[len[i-1]-1]) if(!(s&t)) dp[i][s]=(dp[i][s]+dp[i-1][t])%mod;
		}
	}
	ll sum=0;
	for(auto s:S[len[rw]-1]) sum=(sum+dp[rw][s])%mod;
	for(int i=1;i<=rw;i++) len[i]=0;
	return sum;
}
int Log[1<<20];
int main() {
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout); 
	for(int i=0;i<(1<<20);i++) if(!(i&(i>>1))&&!(i&(i<<1))) g[i]=1;
	for(int i=2;i<(1<<20);i++) Log[i]=Log[i>>1]+1;
	for(int i=0;i<(1<<20);i++) {
		if(!g[i]) continue;
		for(int j=Log[i];j<=20;j++) S[j].push_back(i);
	}
	n=read();
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			ll tmp=solve(i);
			ans=(ans*tmp)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
