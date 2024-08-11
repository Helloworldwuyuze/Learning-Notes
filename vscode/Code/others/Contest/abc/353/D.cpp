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
#define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

int n,a[N], suf[N], num[N], p[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=10;++i)	p[i]=p[i-1]*10%MOD;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i){
		int t=a[i], s=0;
		while(t)	t/=10, ++s;
		num[i]=s;
	}
	for(int i=n;i;--i)	suf[i]=(suf[i+1]+p[num[i]])%MOD;
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+a[i]*suf[i+1]%MOD+a[i]*(i-1)%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}