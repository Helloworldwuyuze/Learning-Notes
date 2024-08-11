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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, a[N], col[N], sum, cntq, cntu, nn, ans[N];
struct opt{
	int l, r, t, id;
	bool operator <(const opt &other){
		return l/nn == other.l/nn ? r/nn == other.r/nn ? t < other.t : r < other.r : l < other.l;
	}
}opq[N], opu[N];

void add(int x){ sum += (++col[x]) == 1;}
void del(int x){ sum -= (--col[x]) == 0;}

void upd(int x,int t){
	if(opq[x].l <= opu[t].l && opu[t].l <= opq[x].r)
		add(opu[t].r), del(a[opu[t].l]);
	swap(a[opu[t].l], opu[t].r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = pow(n, 0.6666);
	for(int i=1;i<=n;++i)   cin>>a[i];
	for(int i=1;i<=m;++i){
		char op; int x, y;
		cin>>op>>x>>y;
		if(op == 'Q')	++cntq, opq[cntq] = {x, y, cntu, cntq};
		else	++cntu, opu[cntu] = {x, y};
	}
	sort(opq+1, opq+1+cntq);
	int l = 1, r = 0, t = 0;
	for(int i=1;i<=cntq;++i){
		while(r<opq[i].r)	add(a[++r]);
		while(l>opq[i].l)	add(a[--l]);
		while(r>opq[i].r)	del(a[r--]);
		while(l<opq[i].l)	del(a[l++]);
		while(t<opq[i].t)	upd(i, ++t);
		while(t>opq[i].t)	upd(i, t--);
		// cout<<opq[i].l<<" "<<opq[i].r<<" "<<opq[i].t<<" "<<opq[i].id<<" "<<l<<" "<<r<<" "<<t<<" "<<sum<<endl;
		ans[opq[i].id] = sum;
	}
	for(int i=1;i<=cntq;++i)	cout<<ans[i]<<endl;
	return 0;
}