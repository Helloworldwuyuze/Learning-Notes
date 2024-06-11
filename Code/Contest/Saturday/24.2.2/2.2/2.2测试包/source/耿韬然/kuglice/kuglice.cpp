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

/*
#define N 3010
int n;
int a[N];

int main() {
//	freopen("kuglice.in", "r", stdin);
//	freopen("kuglice.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; ++i) a[i]=read();
	 
	return 0;
}
*/


#define N 3010
int n;
int a[N];
int vis[N];
int sc[2];

void dfs(int l, int r, bool dep) {
//	printf("%d %d %d %d %d\n", l, r, sc[0], sc[1], dep);
	if (l>r) return;
	if (l==r) {
		sc[dep]+=!vis[a[l]];
		return;
	}
	if (vis[a[l]] && !vis[a[r]]) {
		vis[a[r]]=1, ++sc[dep];
		dfs(l, r-1, !dep);
		return;
	}
	if (!vis[a[l]]) {
		vis[a[l]]=1, ++sc[dep];
		dfs(l+1, r, !dep);
		return;
	}
	sc[dep]+=!vis[a[l]];
	vis[a[l]]=vis[a[r]]=1;
	dfs(l+1, r-1, dep);
	return;
}

int main() {
	freopen("kuglice.in", "r", stdin);
	freopen("kuglice.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; ++i) a[i]=read();
	dfs(1, n, 0);
	printf("%d:%d", sc[0], sc[1]);
	return 0;
}

