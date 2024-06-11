#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 5e1 + 10;
const int M = 1e4 + 10;

int n,x;
int a[N],b[N];
bool f[N][M];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>x;
	for(int i=1;i<=n;++i)	cin>>a[i]>>b[i];
	f[0][0]=true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=x;++j){
			for(int k=0;k*a[i]<=j&&k<=b[i];++k){
				if(f[i-1][j-k*a[i]])	f[i][j]=true;
			}
		}
	}
	cout<<(f[n][x]?"Yes":"No");
	return 0;
}

