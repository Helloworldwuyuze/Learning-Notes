#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

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

struct node{
	int x, id;
	bool operator <(const node &other) const { return x<other.x; }
}a[N], b[N];
int n, fa[N], siz[N], ans, cnt, T, tot;

int find(int x){ return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }

signed main(){
//	freopen("shark.in","r",stdin);
//	freopen("shark.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>T;	
	for(int i=1;i<=n;++i)	cin>>a[i].x, a[i].id = i;
	for(int i=1;i<=n;++i)	cin>>b[i].x, b[i].id = i;
	sort(a+1, a+1+n), sort(b+1, b+1+n);
	for(int i=1;i<=n;++i)	fa[i] = i, siz[i] = 1;
	for(int i=1;i<=n;++i){
//		cout<<a[i].x<<" "<<b[i].x<<" "<<a[i].id<<" "<<b[i].id<<endl;
		int fx = find(a[i].id), fy = find(b[i].id);
		ans += (a[i].x - b[i].x) * (a[i].x - b[i].x) % MOD;
		ans %= MOD;
		if(fx == fy)	continue;
//		cout<<a[i].id<<" "<<b[i].id<<" "<<fx<<" "<<fy<<" "<<siz[fx]<<" "<<siz[fy]<<endl; 
		fa[fx] = fy, siz[fy] += siz[fx];
	}
//	for(int i=1;i<=n;++i)	cout<<fa[i]<<" "<<siz[i]<<endl;
	for(int i=1;i<=n;++i)
		if(find(i) == i)	cnt += siz[i]-1;
	cout<<ans<<" ";
	if(T)	cout<<cnt<<endl;
	else	cout<<endl;
	return 0;
}
/*
5 1
7 9 3 1 10
5 8 6 2 4
*/

