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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int a[N], s[N], n, p, c[N], m, ans;

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=m;i+=lowbit(i))	b[i] += k;}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	cin>>p;
	for(int i=1;i<=n;++i)	a[i] -= p, s[i] = s[i-1] + a[i], c[++m] = s[i];
	sort(c+1, c+1+m);
	m = unique(c+1, c+1+m) - c - 1;
	for(int i=1;i<=n;++i)	s[i] = lower_bound(c+1, c+1+m, s[i]) - c;
	for(int i=1;i<=n;++i)
		ans += query(s[i]), update(s[i], 1);
	for(int i=1;i<=n;++i)	ans += c[s[i]] >= 0;
	cout<<ans<<endl;
	return 0;
}