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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, q, l, r;
int w[N];

int phi(int x){
	int sum = x;
	for(int i=2;i*i<=x;++i)
		if(x%i==0){
			sum/=i, sum*=(i-1);
			while(x%i==0)	x/=i;
		}
	// cerr<<x<<endl;
	if(x!=1)	sum/=x, sum*=(x-1);
	return sum;
}
map<int,int> ma;

int ksm(int x,int m,int MOD){
	int ans = 1;
	while(m){
		if(m&1)	if((ans*=x) >= MOD)	ans=ans%MOD+MOD;
		if((x*=x) >= MOD)	x=x%MOD+MOD;
		m>>=1;
	}
	return ans;
}

int solve(int x,int m){
	if(x == r+1 || m == 1)	return 1;
	int tmp = solve(x+1, ma[m]);
	return ksm(w[x], tmp, m);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	int tmp = m;
	while(tmp != 1)	ma[tmp] = phi(tmp), tmp = ma[tmp];
	ma[tmp] = 1;
	for(int i=1;i<=n;++i)	cin>>w[i];
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<solve(l, m)%m<<endl;
	}
	return 0;
}