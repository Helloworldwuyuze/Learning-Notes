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
const int N = 5e4 + 10;
const int M = 1e6 + 10;

int n, a[N], nn, m, col[N], cor[N], q, ans[N], sum;
struct node{
	int l, r, f, id;
	bool operator <(const node &other) const {
		if(l/nn == other.l/nn)  return (l/nn%2)?r>other.r:r<other.r;
		return l/nn > other.l/nn;
	}
}range[N<<2];

inline void addr(int x){ sum += col[x], ++cor[x];}
inline void addl(int x){ sum += cor[x], ++col[x];}
inline void delr(int x){ sum -= col[x], --cor[x];}
inline void dell(int x){ sum -= cor[x], --col[x];}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)   cin>>a[i];
	cin>>m; nn = sqrt(m<<2);
	for(int i=1,x,y,_x,_y;i<=m;++i){
		cin>>x>>y>>_x>>_y;
		range[++q] = node{y, _y, 1, i};
		range[++q] = node{x-1, _y, -1, i};
		range[++q] = node{y, _x-1, -1, i};
		range[++q] = node{x-1, _x-1, 1, i};
	}
	sort(range+1, range+1+q);
	int l = 0, r = 0;
	for(int i=1;i<=q;++i){
		while(r<range[i].r)	addr(a[++r]);
		while(r>range[i].r)	delr(a[r--]);
		while(l<range[i].l)	addl(a[++l]);
		while(l>range[i].l)	dell(a[l--]);
		ans[range[i].id] += sum * range[i].f;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}