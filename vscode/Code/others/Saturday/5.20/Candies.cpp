#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e2 + 10;
const int M = 1e5 + 10;
const int MOD = 1e9 + 7;

int n,k,s[N][M],sum;
int a[N];
int f[N][M];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<k){
		cout<<0<<endl;
		return 0;
	}
	f[1][0]=s[1][0]=1;
	for(int i=1;i<=k;++i){
		f[1][i]=(i<=a[1]);
		s[1][i]=s[1][i-1]+f[1][i];
	}
	for(int i=2;i<=n;++i){
		f[i][0]=s[i][0]=1;
		for(int j=1;j<=k;++j){
			if(j<=a[i])	f[i][j]=s[i-1][j];
			else	f[i][j]=(s[i-1][j]-s[i-1][j-a[i]-1]+MOD)%MOD;
			s[i][j]=(s[i][j-1]+f[i][j])%MOD;
		}
	}
	cout<<f[n][k];
	return 0;
}

