#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,m,phi=MOD-1;
int t[N],cnt,sum=1;
bool flag=false;

int ksm(int x,int k){
	int ans=1;
	while(k){
		if(k&1)	ans=ans*x%MOD;
		x=x*x%MOD; k>>=1; 
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;++i)	cin>>x, t[x]++, m=max(m,x);
	for(int i=1;i<=m;++i){
		if((t[i]+1)%2==0&&!flag)	sum=sum*(t[i]+1)/2%phi, flag=true;
		else	sum=sum*(t[i]+1)%phi;
	}
	int ans=1;
	for(int i=1;i<=m;++i){
		if(t[i]==0)	continue;
		int y;
		if(flag)	y=sum*t[i]%phi;
		else	y=sum*t[i]/2%phi;
		ans=ans*ksm(i,y+phi)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}

