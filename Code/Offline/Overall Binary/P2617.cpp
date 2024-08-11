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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e5 + 10;
const int M = 1e6 + 10;

int n, m, t;
struct opt{
	int op, x, y, id, k;
}q[N], q1[N], q2[N];
int ans[N], cnt, tot, a[N], c[N];

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))	b[i] += k; }
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

void solve(int l,int r,int L,int R){
	if(l == r){
		for(int i=L;i<=R;++i)
			if(q[i].op == 0)	ans[q[i].id] = l;
		return ;
	} 
	int mid = l+r>>1, cnt1 = 0, cnt2 = 0;
	for(int i=L;i<=R;++i)
		if(q[i].op == 0){
			int tmp = query(q[i].y) - query(q[i].x-1);
//			cout<<i<<" "<<q[i].x<<" "<<q[i].y<<" "<<q[i].k<<" "<<tmp<<endl;
			if(tmp >= q[i].k)	q1[++cnt1] = q[i];
			else	q[i].k -= tmp, q2[++cnt2] = q[i];
		}else{
			if(q[i].y <= mid)	q1[++cnt1] = q[i], update(q[i].x, q[i].op);
			else	q2[++cnt2] = q[i];
		}
	for(int i=1;i<=cnt1;++i)
		if(q1[i].op != 0)	update(q1[i].x, -q1[i].op);
//	cout<<"###"<<l<<" "<<r<<" "<<L<<" "<<R<<"###"<<endl;
//	for(int i=1;i<=cnt1;++i)	cout<<q1[i].op<<" "<<q1[i].x<<" "<<q1[i].y<<" "<<q1[i].id<<" "<<q1[i].k<<endl;
//	cout<<endl;
//	for(int i=1;i<=cnt2;++i)	cout<<q2[i].op<<" "<<q2[i].x<<" "<<q2[i].y<<" "<<q2[i].id<<" "<<q2[i].k<<endl;
//	cout<<endl;
	for(int i=1;i<=cnt1;++i)	q[i+L-1] = q1[i];
	for(int i=1;i<=cnt2;++i)	q[L+cnt1+i-1] = q2[i];
	solve(l, mid, L, L+cnt1-1), solve(mid+1, r, L+cnt1, R);	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i], q[++tot] = {1, i, a[i], 0, 0}, c[++t] = a[i];
	for(int i=1;i<=m;++i){
		char op; int l, r, k, x, y;
		cin>>op;
		if(op == 'C'){
			cin>>x>>y;
			q[++tot] = {-1, x, a[x], 0, 0};
			q[++tot] = {1, x, y, 0, 0}, a[x] = y;
			c[++t] = y;
		}else	cin>>l>>r>>k, q[++tot] = {0, l, r, ++cnt, k};
	}
	sort(c+1, c+1+t);
	t = unique(c+1, c+1+t) - c - 1;
	for(int i=1;i<=tot;++i)
		if(q[i].op != 0)	q[i].y = lower_bound(c+1, c+1+t, q[i].y) - c;
//	for(int i=1;i<=t;++i)	cout<<c[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=tot;++i)
//		cout<<q[i].op<<" "<<q[i].x<<" "<<q[i].y<<" "<<q[i].k<<" "<<q[i].id<<endl;
	solve(1, t, 1, tot);
	for(int i=1;i<=cnt;++i)
		cout<<c[ans[i]]<<endl;
	return 0;
}