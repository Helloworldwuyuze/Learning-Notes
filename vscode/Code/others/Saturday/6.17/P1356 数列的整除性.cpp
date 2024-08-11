#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

const int N = 1e2 + 10;
const int M = 1e5 + 10;
int T,n,k;
bool f[M][N];

int fun(int x){
	return (x%k+k)%k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		f[0][0]=1;
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			int x;
			cin>>x;
			for(int j=0;j<k;++j){
				if(f[i-1][j])	f[i][fun(j+x)]=f[i][fun(j-x)]=1;
			}
		}
//		for(int i=0;i<=k;++i)	cout<<f[i]<<" ";
		if(f[n][0])	cout<<"Divisible"<<endl;
		else	cout<<"Not divisible"<<endl;
	}
	return 0;
}

