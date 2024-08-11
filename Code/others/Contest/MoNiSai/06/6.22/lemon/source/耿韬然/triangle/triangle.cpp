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

#define N 2010
#define M 300010
int n, m, t1, t2, cnt;
bool d[N][N], f[N][N];

signed main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	n=read(), m=read();
	for (int i=1; i<=m; ++i) t1=read(), t2=read(), d[t1][t2]=1, d[t2][t1]=1;
	for (int i=1; i<=n; ++i) for (int j=i+1; j<=n; ++j) {
		for (int k=j+1; k<=n; ++k) {
			if (d[i][j]&&d[i][k]&&d[j][k]) ++cnt;
			if (!d[i][j]&&!d[i][k]&&!d[j][k]) ++cnt;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}
