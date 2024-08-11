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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int dfn[N], rk[N], siz[N], idx;
int blk[N], l[N], r[N], suf[N], cnt, nn;
int n, m;
struct node{
	int x, y, id;
	bool operator <(const node &other) const{ return x < other.x;}
}a[N], b[N];
vector<int> g[N];

void dfs(int x){
	dfn[x] = ++idx, rk[idx] = x;
	siz[x] = 1;
	for(int y:g[x])	dfs(y), siz[x] += siz[y];
}
void init(){
	nn = 1000;
	for(int i=1;i<=n;++i){
		blk[i] = (i-1)/nn+1;
		l[i] = (blk[i]-1)*nn+1;
		r[i] = min(blk[i]*nn, n);
		b[i] = a[i];
	}
	cnt = blk[n];
	for(int i=1;i<=cnt;++i)
		sort(a+l[i], a+1+r[i]);
	for(int i=1;i<=cnt;++i){
		suf[r[i]] = a[r[i]].id;
		for(int j = r[i]-1; j>=l[i]; --j)
			if(a[j].y >= b[suf[j+1]].y)	suf[j] = j;
			else	suf[j] = suf[j+1];
	}
}
int query(int left,int right,int x){
	int bl = blk[left], br = blk[right], ans = 0;
	if(bl == br){
		for(int i=left;i<=right;++i)
			if(b[i].x > x && b[i].y > b[ans].y)	ans = i;
		return ans;
	}
	for(int i=left;i<=r[bl];++i)
		if(b[i].x > x && b[i].y > b[ans].y)	ans = i;
	for(int i=l[br];i<=right;++i)
		if(b[i].x > x && b[i].y > b[ans].y) ans = i;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=2,x;i<=n;++i)
		cin>>x>>a[i].x>>a[i].y, g[x+1].pb(i), a[i].id = i;
	dfs(1); init();
	return 0;
}