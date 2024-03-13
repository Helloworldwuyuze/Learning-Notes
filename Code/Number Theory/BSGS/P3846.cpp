#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>

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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int a,b,p,q;

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%p;
		x=x*x%p; m>>=1;
	}
	return ans;
}

int solve(){
	map<int,int> ma;
	int base=b%p;
	ma[base]=0;
	for(int i=1;i<=q;++i){
		base=base*a%p;
		ma[base]=i;
	}
	base=ksm(a,q);
	int t=1;
	for(int i=1;i<=q;++i){
		t=t*base%p;
		if(ma[t]){ return ((i*q-ma[t])%p+p)%p;}
	}
	return -1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>p>>a>>b; q=sqrt(p)+1;
	// cout<<ksm(539425167,46341)<<endl;
	int ans=solve();
	if(ans==-1)	cout<<"no solution"<<endl;
	else	cout<<ans<<endl;
	return 0;
}