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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct node{
	int t, x, y, id;
	bool operator <(const node &other) const { return t == other.t ? x == other.x ? y>other.y : x<other.x : t>other.t; }
}a[N], tmp[N];
int n, m, rk[N], x[N], ans[N];

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))	b[i] += k; }
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

void CDQ(int l,int r){
	if(l == r)	return ;
	int mid = l+r>>1;
	CDQ(l, mid), CDQ(mid+1, r);
	int i = l, j = mid+1, idx = 0;
	while(i<=mid && j<=r){
		if(a[i].x <= a[j].x)	tmp[l+idx] = a[i], update(a[i].y, 1), ++i, ++idx;
		else	tmp[l+idx] = a[j], ans[a[j].y] += query(n) - query(a[j].y-1), ++j, ++idx;
	}
	while(i<=mid)	tmp[l+idx] = a[i], update(a[i].y, 1), ++i, ++idx;
	while(j<=r)	tmp[l+idx] = a[j], ans[a[j].y] += query(n) - query(a[j].y-1), ++j, ++idx;
	cerr<<"###"<<l<<" "<<r<<"###"<<endl;
	for(int i=1;i<=n;++i)	cout<<query(i)<<" ";
	cout<<endl;
	for(int i=1;i<=n;++i)	cout<<ans[i]<<" ";
	cout<<endl;
	for(int i=l;i<=mid;++i)	update(a[i].y, -1);
	for(int i=l;i<=r;++i)	a[i] = tmp[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i].y, a[i].x = i, rk[a[i].y] = i;
	for(int i=1;i<=m;++i)	cin>>x[i], a[rk[x[i]]].t = i;
	for(int i=1;i<=n;++i)
		if(!a[i].t)	a[i].t = m;
	sort(a+1, a+1+n);
	for(int i=1;i<=n;++i)
		cout<<i<<" "<<a[i].t<<" "<<a[i].x<<" "<<a[i].y<<" "<<endl;
	CDQ(1, n);
//	cerr<<"QAQ"<<endl;
	long long sum = 0;
	for(int i=1;i<=n;++i)	sum += ans[i];
	for(int i=1;i<=m;++i){
		cout<<sum<<endl;
		sum -= ans[x[i]];
	}
	return 0;
}

