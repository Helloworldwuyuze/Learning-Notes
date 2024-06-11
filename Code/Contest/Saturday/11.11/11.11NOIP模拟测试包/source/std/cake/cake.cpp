#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2005;
int n;
ll a[N*2],f[2*N][2*N];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)f[i][i]=a[i];
	for(int len=1;len<=n;len++){
		for(int i=1;i<=2*n;i++){
			int j=i+len-1;
			if(i-1<=0||j+1>2*n)continue; 
			if(len%2==1){
				if(a[i-1]>a[j+1]){
					f[i-1][j]=max(f[i-1][j],f[i][j]);
				}else{
					f[i][j+1]=max(f[i][j+1],f[i][j]);
				}
			}else{
				f[i-1][j]=max(f[i-1][j],f[i][j]+a[i-1]);
				f[i][j+1]=max(f[i][j+1],f[i][j]+a[j+1]);
			}
		}
	}
	ll res=0;
	for(int i=1;i<=n+1;i++)res=max(res,f[i][i+n-1]);
	printf("%lld\n",res);
	return 0;
}
