#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+10;
int n;
int a[N*2];
int f[N*2][N*2];

int ans=0;

signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
		f[i][i]=a[i];
		f[i+n][i+n]=a[i];
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n*2;l++){
			int r=l+len-1;
			if(len%2==1){
				f[l][r]=max(f[l][r],f[l+1][r]+a[l]);
				f[l][r]=max(f[l][r],f[l][r-1]+a[r]);
			}else{
				if(a[l]>a[r]){
					f[l][r]=max(f[l][r],f[l+1][r]);
				}else{
					f[l][r]=max(f[l][r],f[l][r-1]);
				}
			}
			if(len==n){
				ans=max(ans,f[l][r]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
