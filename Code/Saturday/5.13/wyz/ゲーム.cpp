#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int na,nb;
int a[N],b[N];
int f[N][N];

int main(){
	cin.tie(0),cout.tie(0);
	cin>>na>>nb;
	for(int i=1;i<=na;++i)	cin>>a[i];
	for(int j=1;j<=nb;++j)	cin>>b[j];
	for(int i=na+1;i>0;--i){
		for(int j=nb+1;j>0;--j){
			if(i==na+1&&j==nb+1)	continue;
			if((i+j)%2==0){
				f[i][j]=max(i==na+1?0:a[i]+f[i+1][j],j==nb+1?0:b[j]+f[i][j+1]);
			}else{
				f[i][j]=min(i==na+1?INF:f[i+1][j],j==nb+1?INF:f[i][j+1]);
			}
		}
	}
	cout<<f[1][1]<<endl;
	return 0;
}


