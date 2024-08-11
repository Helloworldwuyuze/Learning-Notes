#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

inline ll read() {
	ll x=0, f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}

#define N 200010
int n, q;
int h[N];
int l, r, x;
int ans;
bool lst;

int main() {
	freopen("zatopljenje.in", "r", stdin);
	freopen("zatopljenje.out", "w", stdout);
	n=read();
	q=read();
	//printf("%d %d\n", n, q);
	for (int i=1; i<=n; ++i) h[i]=read();
	while (q--) {
		l=read();
		r=read();
		x=read();
		ans=0, lst=0;
		for (int i=l; i<=r; ++i) {
			if (!lst && h[i]>x) ++ans;
			lst=(h[i]>x);
		}
		printf("%d\n", ans);
	}
	return 0;
}

