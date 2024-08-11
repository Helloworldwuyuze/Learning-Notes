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
const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m, q, h[N], b[N], cnt;
struct edge{
	int u, v, w;
	bool operator <(const edge &other) const{ return w<other.w; }
}e[M];
struct ques{
	int v, x, k, id;
	bool operator <(const ques &other) const{ return x<other.x; }
}qu[M];
int fa[N];

int s[N<<5], root[N], idx, ls[N<<5], rs[N<<5], ans[M];
void update(int &p,int l,int r,int x,int k){
	if(!p)	p=++idx;
	if(l==r)	return (void)(s[p] += k);
	int mid = l+r>>1;
	if(x<=mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
	s[p] = s[ls[p]] + s[rs[p]];
}
int merge(int p,int q,int l,int r){
	if(!p||!q)	return p+q;
	if(l==r)	return s[p] += s[q], p;
	int mid = l+r>>1;
	ls[p] = merge(ls[p], ls[q], l, mid);
	rs[p] = merge(rs[p], rs[q], mid+1, r);
	return s[p] = s[ls[p]] + s[rs[p]], p;
}
int kth(int p,int l,int r,int k){
	if(l==r)	return l;
	int mid = l+r>>1;
	if(k<=s[rs[p]])	return kth(rs[p], mid+1, r, k);
	else	return kth(ls[p], l, mid, k - s[rs[p]]);
}
int find(int x){ return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);}

void print(int x,int l,int r){
	if(!x)	return ;
	cout<<x<<" "<<l<<" "<<r<<" "<<ls[x]<<" "<<rs[x]<<" "<<s[x]<<endl;
	int mid = l+r>>1;
	print(ls[x],l,mid), print(rs[x],mid+1,r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)	cin>>h[i], fa[i] = i, b[++cnt] = h[i];
	sort(b+1, b+1+cnt);
	cnt = unique(b+1, b+1+cnt) - b - 1;
	for(int i=1;i<=n;++i)	h[i] = lower_bound(b+1, b+1+cnt, h[i]) - b;
	for(int i=1;i<=m;++i)	cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=q;++i)	cin>>qu[i].v>>qu[i].x>>qu[i].k, qu[i].id = i;
	sort(e+1, e+1+m); sort(qu+1, qu+1+q);
	for(int i=1;i<=n;++i)	update(root[i], 1, n, h[i], 1);
	// for(int i=1;i<=n;++i)	cout<<root[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=idx;++i)
		// cout<<i<<" "<<s[i]<<" "<<ls[i]<<" "<<rs[i]<<endl;
	int i = 1, j = 1;
	for(; i<=q||j<=m; ){
		// cout<<i<<" "<<j<<" "<<qu[i].x<<" "<<e[j].w<<endl;
		// for(int i=1;i<=n;++i)	cout<<find(i)<<" ";
		// cout<<endl;
		while(qu[i].x<e[j].w && i<=q){
			int fx = find(qu[i].v);
			// cout<<"QUERY::"<<qu[i].v<<" "<<qu[i].x<<" "<<qu[i].k<<" "<<qu[i].id<<" "<<fx<<endl;
			// print(root[fx],1,n);
			if(s[root[fx]]<qu[i].k)	ans[qu[i].id] = -1;
			else	ans[qu[i].id] = b[kth(root[fx], 1, n, qu[i].k)];
			++i;
		}
		do{
			int fx = find(e[j].u), fy = find(e[j].v);
			if(fx==fy){ ++j; continue;}
			fa[fy] = fx, root[fx] = merge(root[fx], root[fy], 1, n);
			++j;
		}while(e[j].w == e[j-1].w && j<=m);
	}
	for(int i=1;i<=q;++i)	cout<<ans[i]<<endl;
	return 0;
}