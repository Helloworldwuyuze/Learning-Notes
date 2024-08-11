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

int n, a[N], s[N], b[N], lo, base[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	a[1] = 10, a[2] = 9; s[1] = 10, s[2] = 19;
	for(int i=3;s[i-1]<=1000000000000000000ll;++i)
		if(i&1)	a[i] = a[i-1]*10, s[i] = s[i-1] + a[i];
		else	a[i] = a[i-1], s[i] = s[i-1] + a[i];
	base[0] = 1;
	for(int i=1;i<=18;++i)	base[i] = base[i-1]*10;
	for(int i=1;s[i-1]<=1000000000000000000ll;++i){
		if(s[i] >= n){
			if(i == 1){
				cout<<n-1<<endl;
				return 0;
			}
			// cout<<n<<" "<<s[i-1]<<" "<<base[i-1>>1]<<endl;
			n -= s[i-1]-base[i-1>>1]+1;
			// cout<<i<<" "<<n<<endl;
			if(i&1){
				while(n)	b[++lo] = n%10, n/=10;
				for(int i=lo;i;--i)	cout<<b[i];
				for(int i=2;i<=lo;++i)	cout<<b[i];
				cout<<endl;
			}else{
				while(n)	b[++lo] = n%10, n/=10;
				for(int i=lo;i;--i)	cout<<b[i];
				for(int i=1;i<=lo;++i)	cout<<b[i];
				cout<<endl;
			}
			return 0;
		}
	}
	return 0;
}