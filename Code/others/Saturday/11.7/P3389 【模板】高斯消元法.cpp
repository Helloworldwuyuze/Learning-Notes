#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n;
double a[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	
		for(int j=1;j<=n+1;++j)	cin>>a[i][j];
	for(int i=1;i<=n;++i){
		int pos=i;
		for(int j=i+1;j<=n;++j)
			if(fabs(a[j][i])>fabs(a[pos][i]))	pos=j;
		if(pos!=i)
			for(int j=1;j<=n+1;++j)	swap(a[i][j],a[pos][j]);
		if(fabs(a[i][i])<eps){
			cout<<"No Solution"<<endl;
			return 0;
		}
		for(int j=n+1;j>=i;--j)	a[i][j]/=a[i][i];
		for(int j=1;j<=n;++j){
			if(j==i)	continue;
			double t=a[j][i];
			for(int k=i;k<=n+1;++k)	a[j][k]-=t*a[i][k];
		}
	}
//	for(int i=1;i<=n;++i,cout<<endl)
//		for(int j=1;j<=n+1;++j)
//			cout<<a[i][j]<<" ";
	for(int i=1;i<=n;++i)	printf("%.2lf\n",a[i][n+1]);
	return 0;
}

