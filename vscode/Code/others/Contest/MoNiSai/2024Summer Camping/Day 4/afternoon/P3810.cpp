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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

struct node{
	int x, y, z, id, siz;
	bool operator <(const node &other) const { return x == other.x ? y == other.y ? z<other.z : y<other.y : x<other.x; }
	bool operator ==(const node &other) const { return x==other.x && y==other.y && z==other.z; }
}a[N], tmp[N];
int n, K, ans[N], idx, t[N], m;

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=K;i+=lowbit(i))	b[i] += k; }
int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit 
map<node, int> ma;

void CDQ(int l,int r){
	if(l == r)	return ;
	int mid = l+r>>1;
	CDQ(l, mid), CDQ(mid+1, r);
	int i = l, j = mid+1;
	idx = 0;
	while(i<=mid && j<=r){
		if(a[i].y<=a[j].y)	tmp[l+idx] = a[i], update(a[i].z, ma[a[i]]), ++i, ++idx;
		else	tmp[l+idx] = a[j], ans[a[j].id] += query(a[j].z), ++j, ++idx;
	}
	while(i<=mid)	tmp[l+idx] = a[i], update(a[i].z, ma[a[i]]), ++i, ++idx;
	while(j<=r)	tmp[l+idx] = a[j], ans[a[j].id] += query(a[j].z), ++j, ++idx;
	for(int i=l;i<=mid;++i)	update(a[i].z, -ma[a[i]]);
	for(int i=l;i<=r;++i)
		a[i] = tmp[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;++i)	cin>>a[i].x>>a[i].y>>a[i].z, a[i].id = i, ++ma[a[i]];
	sort(a+1, a+1+n);
	m = unique(a+1, a+1+n) - a - 1;
	for(int i=1;i<=m;++i)	ans[a[i].id] += ma[a[i]]-1;
	CDQ(1, m);
	for(int i=1;i<=m;++i)	t[ans[a[i].id]]+=ma[a[i]];
	for(int i=0;i<n;++i)	cout<<t[i]<<endl;
	return 0;
}

