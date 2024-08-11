#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int t,x,y,fact[N],infact[N],p[N],prime[N],cnt,minn[N];

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}

int C(int n,int m){
	if(n<m)	return 0;
	if(m==0)	return 1;
	return fact[n]*infact[n-m]%MOD*infact[m]%MOD;
}

void Prime(){
	for(int i=2;i<=1000000;++i){
		if(!prime[i])	prime[++cnt]=i, minn[i]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=1000000;++j){
			prime[i*prime[j]]=1;
			minn[i*prime[j]]=prime[j];
			if(i%prime[j]==0)	break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Prime();
	fact[0]=1;
	for(int i=1;i<=N-10;++i)	fact[i]=fact[i-1]*i%MOD;
	infact[N-10]=ksm(fact[N-10],MOD-2);
	for(int i=N-11;i>=0;--i)	infact[i]=infact[i+1]*(i+1)%MOD;
	p[0]=1;
	for(int i=1;i<=1000000;++i)	p[i]=p[i-1]*2%MOD;
	cin>>t;
	while(t--){
		cin>>x>>y;
		int ans=p[y-1];
		while(x>1){
			int sum=0, xx=x;
			while(xx%minn[x]==0)	xx/=minn[x], ++sum;
			ans=ans*C(sum+y-1,y-1)%MOD;
			x=xx;
		}
		if(x!=1)	ans=ans*C(y,y-1)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
