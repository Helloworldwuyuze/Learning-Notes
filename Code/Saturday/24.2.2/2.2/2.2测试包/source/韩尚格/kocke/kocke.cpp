#include<iostream>
#define int long long
using namespace std;
const int N=5e3+5,mod=1e9+7;
int dp[N][N],ans;
int n,k;
signed main(){
	freopen("kocke.in","r",stdin);
	freopen("kocke.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) dp[1][i]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(j>1) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
			if(j<k) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
		}
	}
	for(int i=1;i<=k;i++){
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
