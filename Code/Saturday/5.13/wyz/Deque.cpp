#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

const int N = 3e3 + 10;
int n,a[N];
#define int long long
#define endl '\n'
int f[N][N];

signed main(){
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
//	for(int i=1;i<=n;++i){
//		f[i][i]=((n-1)%2==0?1:-1)*a[i];
//	}
	for(int k=1;k<=n;++k){
		for(int i=1;i+k-1<=n;++i){
			int j=i+k-1;
			if((i-1+n-j)%2==0){
				f[i][j]=max(a[i]+f[i+1][j],a[j]+f[i][j-1]);
			}else{
				f[i][j]=min(f[i+1][j]-a[i],f[i][j-1]-a[j]);
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<f[i][j]<<" ";
//		} 
//		cout<<endl;
//	}
	cout<<f[1][n]<<endl;
	return 0;
}


