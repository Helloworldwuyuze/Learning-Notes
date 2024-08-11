#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
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
// #define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

int n,t,f[100];
int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}

int maxx[N], st[N][20];
void push_up(int p){
	maxx[p]=max(maxx[p<<1], maxx[p<<1|1]);
}
void update(int p,int l,int r,int x,int k){
	if(l==r){ maxx[p]+=k; return ;}
	int mid=l+r>>1;
	if(x<=mid)	update(p<<1, l, mid, x, k);
	else	update(p<<1|1, mid+1, r, x, k);
	push_up(p);
}
int query(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return maxx[p];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	f[0]=1;
	cin>>n;
	// cout<<n<<endl;
	int nn=n; while(nn)	++t, nn/=10;
	nn=n;
	// cout<<"QAQ"<<endl;
	for(int i=1;i<=70;++i){
		f[i]=(ksm(ksm(10,t),ksm(2,i-1))*f[i-1]+f[i-1])%MOD;
	}
	int ans=0, lo=0, s=0;
	for(int i=62;i>=0;--i)
		if(s+(1ll<<i)<=n){
			// cout<<i<<" "<<f[i]<<" "<<s<<endl;
			ans=(ans+ksm(ksm(10, s),t)*f[i]%MOD)%MOD, s+=(1ll<<i);
		}
	cout<<ans*(nn%MOD)%MOD<<endl;
	return 0;
}