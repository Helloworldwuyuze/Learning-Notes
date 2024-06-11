#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}
int fact[N],infact[N],in[N],n,m;

struct node{
	int left,right,sum;
}t[N<<2];

void build(int p,int left,int right){
	t[p].left=left, t[p].right=right;
	if(left==right){
		cin>>t[p].sum;
		
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	fact[0]=1;
	for(int i=1;i<=n;++i)	fact[i]=fact[i-1]*i%MOD;
	infact[n]=ksm(fact[n],MOD-2);
	for(int i=n-1;i>=0;--i)	infact[i]=infact[i+1]*(i+1)%MOD;
	in[0]=1;
	for(int i=1;i<=n;++i)	in[i]=infact[i]*fact[i-1]%MOD;
	build(1,1,n);
	
	return 0;
}

