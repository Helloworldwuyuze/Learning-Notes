#include<iostream>
using namespace std;
const int N=3e3+5;
int n;
int a[N],dp[N][N],L[N],R[N],m,x,y;
int main(){
	freopen("kuglice.in","r",stdin);
	freopen("kuglice.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(!L[a[i]]){
			L[a[i]]=i;
			m++;
		}
	}
	for(int i=n;i;i--){
		if(!R[a[i]]) R[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(L[a[i]]==R[a[i]]) dp[i][i]=1;
	}
	for(int len=1;len<n;len++){
		for(int l=1;l<=n-len;l++){
			int r=l+len;
			if(L[a[l]]>=l) dp[l][r]=(R[a[l]]<=r)-dp[l+1][r];
			else dp[l][r]=-dp[l+1][r];
			if(R[a[r]]<=r) dp[l][r]=max(dp[l][r],(L[a[r]]>=l)-dp[l][r-1]);
			else dp[l][r]=max(dp[l][r],-dp[l][r-1]);
		}
	}
	x=(m+dp[1][n])/2,y=(m-dp[1][n])/2;
	cout<<x<<":"<<y<<"\n";
	return 0;
}
