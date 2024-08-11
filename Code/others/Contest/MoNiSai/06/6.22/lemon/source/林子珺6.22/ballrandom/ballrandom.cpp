#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp_make_pair
int n,k,a[N];
int qpow(int a,int p){
	int res=1;
	while(p){
		if(p&1)res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
void solve(){
	cin>>n>>k;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum=(sum+a[i])%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=(ans+(a[i]*inv(sum)%mod*a[j]%mod*inv(sum)%mod*qpow(abs(i-j),k))%mod)%mod;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("ballrandom.in","r",stdin);
	freopen("ballrandom.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

