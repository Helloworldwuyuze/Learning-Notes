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

#define N 300010
int n; ll ans;
int a[N]; bool flag;

signed main() {
	freopen("meximum.in", "r", stdin);
	freopen("meximum.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; ++i) a[i]=read();
	for (int i=1; i<=n; ++i) {
		for (int j=i; j<=n; ++j) {
			for (int x=0; ; ++x) {
				flag=0;
				for (int k=i; k<=j; ++k) {
					if (a[k]==x) {flag=1; break;}
				}
				if (flag) continue;
				ans+=x; break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
