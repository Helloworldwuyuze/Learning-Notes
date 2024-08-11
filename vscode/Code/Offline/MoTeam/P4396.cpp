#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n, a[N], nn, m, col[N], cnt[N], ans1[N], ans2[N];
struct node{
	int l, r, id, x, y;
	bool operator <(const node &other) const {
		if(l/nn == other.l/nn)  return (l/nn%2)?r>other.r:r<other.r;
		return l/nn > other.l/nn;
	}
}range[N];

struct tree{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i)) b[i] += k;}
	int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i)) ans += b[i]; return ans;}
	#undef lowbit
}t1,t2;

inline void add(int x){
	t1.update(x, 1);
	if(++col[x]==1)	t2.update(x, 1);
}
inline void del(int x){
	t1.update(x, -1);
	if(--col[x]==0)	t2.update(x, -1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = sqrt(m*log2(m));
	for(int i=1;i<=n;++i)   cin>>a[i];
	for(int i=1;i<=m;++i)   cin>>range[i].l>>range[i].r>>range[i].x>>range[i].y, range[i].id = i;
	sort(range+1, range+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<range[i].r)	add(a[++r]);
		while(l>range[i].l)	add(a[--l]);
		while(r>range[i].r)	del(a[r--]);
		while(l<range[i].l)	del(a[l++]);
		ans1[range[i].id] = t1.query(range[i].y) - t1.query(range[i].x-1);
		ans2[range[i].id] = t2.query(range[i].y) - t2.query(range[i].x-1);
	}
	for(int i=1;i<=m;++i)	cout<<ans1[i]<<" "<<ans2[i]<<endl;
	return 0;
}