#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>

using namespace std;
#define int long long

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int P = 998244353;

int n;
int a[N],b[N];
int sum[N]={1},p[N],p2[N];
int A=1,C;

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=(ans*x)%P;
		x=(x*x)%P;
		m>>=1;
	}
	return ans%P;
}

signed main(){
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		p[i]=a[i]%P*ksm(b[i],P-2)%P;
		p2[i]=(1-p[i]+P)%P;
		sum[i]=sum[i-1]*p2[i]%P;
		if(i!=n)	A=(A+sum[i])%P;
		C=(C+sum[i-1]*p[i]%P)%P;
	}
	cout<<ksm(((1-C)%P+P)%P,P-2)*A%P;
	return 0;
}

