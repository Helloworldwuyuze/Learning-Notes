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
const int M = 2e6 + 10;

int op, n;
struct node{
	int x, y, t, s, id, f;
	bool operator <(const node &other) const { return t==other.t ? x==other.x ? y<other.y : x<other.x : t<other.t; }
}a[N], tmp[N];
int ans[N], m, cnt, x, y, _x, _y, s;

int b[M];
#define lowbit(x) (x&-x)
void update(int x,int k){ if(!x) return ; for(int i=x;i<=n;i+=lowbit(i))	b[i] += k;}
int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

void CDQ(int l,int r){
	if(l == r)	return ;
	int mid = l+r>>1;
	CDQ(l, mid), CDQ(mid+1, r);
	int i = l, j = mid+1, idx = 0;
	while(i<=mid && j<=r){
		if(a[i].x <= a[j].x)	tmp[l+idx] = a[i], update(a[i].y, a[i].s), ++i, ++idx;
		else	tmp[l+idx] = a[j], ans[a[j].id] += a[j].f*query(a[j].y), ++j, ++idx;
	}
	while(i<=mid)	tmp[l+idx] = a[i], update(a[i].y, a[i].s), ++i, ++idx;
	while(j<=r)	tmp[l+idx] = a[j], ans[a[j].id] += a[j].f*query(a[j].y), ++j, ++idx;
//	cerr<<"###"<<l<<" "<<r<<"###"<<endl;
//	for(int i=1;i<=n;++i)	cout<<query(i)<<" ";
//	cout<<endl;
//	for(int i=1;i<=cnt;++i)	cout<<ans[i]<<" ";
//	cout<<endl;
	for(int i=l;i<=mid;++i)	update(a[i].y, -a[i].s);
	for(int i=l;i<=r;++i)	a[i] = tmp[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while(cin>>op && op!=3){
		switch(op){
			case 0:{ cin>>n; break; }
			case 1:{
				cin>>x>>y>>s; ++m;
				a[m] = {x, y, m, s, 0, 0};
				break;
			}case 2:{
				cin>>x>>y>>_x>>_y;
				++m, ++cnt;
				a[m] = {_x, _y, m, 0, cnt, 1}, ++m;
				a[m] = {_x, y-1, m, 0, cnt, -1}, ++m;
				a[m] = {x-1, _y, m, 0, cnt, -1}, ++m;
				a[m] = {x-1, y-1, m, 0, cnt, 1};
				break;
			}
		}
	}
	sort(a+1, a+1+m);
//	for(int i=1;i<=m;++i)
//		cout<<a[i].t<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].id<<" "<<a[i].s<<" "<<a[i].f<<endl;
	CDQ(1, m);
//	cerr<<"QAQ"<<endl;
	for(int i=1;i<=cnt;++i)
		cout<<ans[i]<<endl;
	return 0;
}

