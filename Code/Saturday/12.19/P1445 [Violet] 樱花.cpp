#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,p[N],cnt,ans=1,a[N];

void prime(){
	for(int i=2;i<=n;++i){
		if(!p[i])	p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=n;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; prime();
	for(int i=1;i<=cnt;++i)
		for(int j=p[i];j<=n;j=j*p[i])	a[i]+=n/j;
	for(int i=1;i<=cnt;++i)
		ans=ans*(2*a[i]+1)%MOD;
	cout<<ans;
	return 0;
}
