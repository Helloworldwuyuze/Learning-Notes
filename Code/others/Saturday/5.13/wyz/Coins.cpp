#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

const int N = 3e3 + 10;
const int M = 2e5 + 10;
int n;
double a[N];
double f[N][N];

int main(){
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			if(j==0)	f[i][j]=f[i-1][j]*(1-a[i]);
			else if(j==i)	f[i][j]=f[i-1][j-1]*a[i];
			else	f[i][j]=f[i-1][j-1]*a[i]+f[i-1][j]*(1-a[i]);
		}
	}
	double ans=0;
	for(int i=(n)/2+1;i<=n;++i){
		ans+=f[n][i];
	}
	printf("%.10lf\n",ans);
	return 0;
}


