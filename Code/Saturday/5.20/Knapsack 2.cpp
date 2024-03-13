#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e2 + 10;
const int M = 1e3 + 10;
int n,m;
int w[N],v[N],f[N*M*10];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>w[i]>>v[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=n*M;j>=v[i];--j){
			f[j]=min(f[j],f[j-v[i]]+w[i]);
		}
	}
	for(int i=n*M;;--i){
		if(f[i]<=m){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

