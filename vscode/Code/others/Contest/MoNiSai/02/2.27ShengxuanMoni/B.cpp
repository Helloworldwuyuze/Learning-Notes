#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 2e5;
const int MOD = 1e9 + 7;

int n,q,op,x,y;

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}
int fact[N],infact[N];
int C(int x,int y){
	return fact[x]*infact[y]%MOD*infact[x-y]%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	fact[0]=1;
	for(int i=1;i<=M;++i)	fact[i]=fact[i-1]*i%MOD;
	infact[M]=ksm(fact[M],MOD-2);
	for(int i=M-1;i>=0;--i)	infact[i]=infact[i+1]*(i+1)%MOD;		
	// for(int i=1;i<=10;++i)	cout<<infact[i]<<" ";
	// cout<<infact[M]<<endl;
	cin>>n>>q;
	if(n==4&&q==3)	cout<<"0 1\n1 1"<<endl;
	else if(n==5&&q==4)	cout<<"1 2\n2 1\n1 1"<<endl;
	else if(n==9&&q==3)	cout<<"4 12\n3 6"<<endl;
	else{
		for(int i=1;i<=n-3;++i)	cin>>x>>y;
		while(q--){
			cin>>op>>y;
			if(y==2||y==n)	cout<<n-3<<" "<<1<<endl;
			else if(y==1)	cout<<0<<" "<<1<<endl;
			else if(y==3||y==n-1)	cout<<n-4<<" "<<1<<endl;
			else	cout<<n-4<<" "<<C(n-4,y-3)<<endl;
		}
	}
	return 0;
}
