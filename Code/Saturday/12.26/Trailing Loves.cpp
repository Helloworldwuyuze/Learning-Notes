#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,b,p[N],minn=INF,cnt;

int fun(int x){
	int ans=0;
	//for(int i=x;i<=n&&i>0;i=i*x)	ans+=n/i;
	int m=n;
	while(m){
		ans+=m/x;
		m/=x;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>b;
	for(int i=2;i*i<=b;++i){
		int sum=0;
		while(b%i==0)	++sum, b/=i;
		if(sum==0)	continue;
		minn=min(minn,fun(i)/sum);
	}
	if(b!=1)	minn=min(minn,fun(b));
	cout<<minn<<endl;
	return 0;
}
