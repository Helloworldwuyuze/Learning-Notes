#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n;
int a[N],b[N],c[N],f[N][3];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;++i){
		f[i][0]=max(f[i-1][1],f[i-1][2])+a[i];
		f[i][1]=max(f[i-1][0],f[i-1][2])+b[i];
		f[i][2]=max(f[i-1][0],f[i-1][1])+c[i];
	} 
	cout<<max(f[n][0],max(f[n][1],f[n][2]));
	return 0;
}

