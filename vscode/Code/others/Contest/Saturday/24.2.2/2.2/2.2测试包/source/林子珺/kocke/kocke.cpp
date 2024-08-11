#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e3+10;
const int mod=1e9+7;
int n,k;
int f[N][N];
int ans;

signed main(){
	freopen("kocke.in","r",stdin);
	freopen("kocke.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i==1){
				f[i][j]=1;
				continue;
			}
			f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k;j++)cout<<f[i][j]<<' ';
//		cout<<endl;
//	} 
	for(int i=1;i<=k;i++)ans=(ans+f[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}

