#include<iostream>
#include<cstdio>
using namespace std;
const int N = 4e5 + 10;
#define int long long
int n,x,a[N],b[N],l=1,maxx,sum,cnt;
signed main(){
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i+n]=a[i];
		b[i+n]=b[i]=a[i]*(a[i]+1)/2;
	}
	for(int i=1;i<=n*2;++i){
		cnt+=a[i], sum+=b[i];
		while(cnt-a[l]>=x)	cnt-=a[l],sum-=b[l++];
		maxx=max(maxx,sum-(cnt-x)*(cnt-x+1)/2);
	}
	cout<<maxx;
	return 0;
}
