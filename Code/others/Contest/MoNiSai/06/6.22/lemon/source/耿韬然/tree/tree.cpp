#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

char buf[1<<20], *p1, *p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)

inline ll read() {
	ll x=0, f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	return x*f;
}

#define N 30010
#define K 1010
int n, q, t1, t2;
int a[N], dep[N];
ll sum, res, ans, d[N][K], siz[N];

#define v e[i].to
int head[N], tot;
struct edge {int to, nxt;} e[N<<1];
void add_edge(int x, int y) {e[++tot]={y, head[x]}, head[x]=tot;}

void dfs1(int u, int fa) {
	dep[u]=dep[fa]+1, siz[u]=1, d[u][0]=a[u];
	for (int i=head[u]; i; i=e[i].nxt) {
		if (v==fa) continue;
		dfs1(v, u);
		for (int j=1; j<K; ++j) d[u][j]+=d[v][j-1];
		siz[u]+=siz[v];
	}
}

void dfs2(int u, int fa) {
	if (u!=1) for (int i=K-1; i>=2; --i) d[u][i]+=d[fa][i-1]-d[u][i-2];
	d[u][1]+=a[fa];
	for (int i=head[u]; i; i=e[i].nxt) {
		if (v==fa) continue;
		dfs2(v, u);
	}
}

signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n=read(), q=read(); bool opt=q<=10000;
	for (int i=1; i<=n; ++i) a[i]=read(), sum+=a[i];
	for (int i=1; i<n; ++i) t1=read(), t2=read(), add_edge(t1, t2), add_edge(t2, t1);
	dfs1(1, 0), dfs2(1, 0);
	for (int i=1; i<=q; ++i) {
		t1=read(), t2=read(), res=d[t1][t2];
		if (opt) {printf("%lld\n", res); continue;}
		ans^=res*i;
	}
	if (!opt) printf("%lld\n", ans);
	return 0;
}
