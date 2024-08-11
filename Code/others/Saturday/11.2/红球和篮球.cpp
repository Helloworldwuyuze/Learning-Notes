#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,m; 
int in[N];

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}

int C(int n,int m){
	int ans=1;
	if(m>n)	return 0;
	for(int i=n;i>=n-m+1;--i)
		ans=ans*i%MOD;
	for(int i=1;i<=m;++i)
		ans=ans*in[i]%MOD;
	return ans;
}

signed main(){
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=2000;++i)	in[i]=ksm(i,MOD-2);
//	cout<<in[2]*2<<endl;
	in[0]=1;
//	cout<<C(3,2)<<endl;
	for(int i=1;i<=m;++i)
		cout<<C(n-m+1,i)*C(m-1,i-1)%MOD<<endl;
	return 0;
}

