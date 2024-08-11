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

int n, m, k, nn, a[N], sum, col[N], ans[N];
struct node{
	int l, r, id;
	bool operator <(const node &other) const {
		if(l/nn == other.l/nn)  return (l/nn%2)?r>other.r:r<other.r;
		return l/nn < other.l/nn;
	}
}range[N];

inline void add(int x){ sum += 2*(++col[x])-1;}
inline void del(int x){ sum -= 2*(--col[x])+1;}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k; nn = sqrt(n);
	for(int i=1;i<=n;++i)   cin>>a[i];
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, range[i] = {x, y, i};
	sort(range+1, range+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<range[i].r)	add(a[++r]);
		while(l>range[i].l)	add(a[--l]);
		while(r>range[i].r)	del(a[r--]);
		while(l<range[i].l)	del(a[l++]);
		ans[range[i].id] = sum;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}