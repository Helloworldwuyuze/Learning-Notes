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

int n, m, cnt, ans[N*5];
struct node{
	int x, y, p, id, f;
	bool operator <(const node &other) const { return x == other.x ? y == other.y ? p > other.p : y < other.y : x < other.x; }
}a[N*5], tmp[N*5];

void CDQ(int l,int r){
	if(l == r)	return ;
	int mid = l+r>>1;
	CDQ(l, mid), CDQ(mid+1, r);
	int i = l, j = mid+1, cnt = 0, idx = 0;
	while(i<=mid && j<=r){
		if(a[i].y <= a[j].y)	tmp[l+idx] = a[i], cnt += a[i].p, ++i, ++idx;
		else	tmp[l+idx] = a[j], ans[a[j].id] += cnt*a[j].f, ++j, ++idx;
		// cout<<"##"<<i<<" "<<j<<"##"<<endl;
		// cout<<cnt<<endl;
	}
	while(i<=mid)	tmp[l+idx] = a[i], ++i, ++idx;
	while(j<=r)	tmp[l+idx] = a[j], ans[a[j].id] += cnt*a[j].f, ++j, ++idx;
	for(int i=l;i<=r;++i)	a[i] = tmp[i];
	// cout<<"###"<<l<<" "<<r<<"###"<<endl;
	// for(int i=1;i<=m;++i)	cout<<ans[i]<<" ";
	// cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i].x>>a[i].y>>a[i].p;
	cnt = n;
	for(int i=1;i<=m;++i){
		int x, y, _x, _y;
		cin>>x>>y>>_x>>_y;
		int xx = max(x, _x), _xx = min(x, _x), yy = max(y, _y), _yy = min(y, _y);
		a[++cnt] = {xx, yy, 0, i, 1}, a[++cnt] = {xx, _yy-1, 0, i, -1};
		a[++cnt] = {_xx-1, yy, 0, i, -1}, a[++cnt] = {_xx-1, _yy-1, 0, i, 1};
	}
	sort(a+1, a+1+cnt);
	// for(int i=1;i<=cnt;++i)
		// cout<<i<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].p<<" "<<a[i].id<<" "<<a[i].f<<endl;
	CDQ(1, cnt);
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}