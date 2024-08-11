#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int a[4005];
ll dp[4005][4005];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	if(n&1)for(int i=1; i<2*n; i++)dp[i][i]=a[i];
	else for(int i=1; i<2*n; i++)dp[i][i+1]=max(a[i],a[i+1]);
	for(int l=(n&1)?2:3; l<=n; l++){
		for(int i=1; i+l-1<2*n; i++){
			int j=i+l-1;
			if(((n-l)&1)==0){
				dp[i][j]=max(dp[i][j-1]+a[j],dp[i+1][j]+a[i]);
				
			}else{
				if(a[i]>a[j])dp[i][j]=dp[i+1][j];
				else dp[i][j]=dp[i][j-1];
			}
		}
	}ll ans=0;
	for(int i=1; i<=n; i++){
		ans=max(ans,dp[i][i+n-1]);
	}cout<<ans;
	return 0;
}
