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

#define N 100010
int n;
int a[N];
int b[N];
int q;
int x;
int ans;

bool vis[N];
bool rev[N];
bool exi[N];

inline int calc() {
	ans=0;
	memset(vis, false, sizeof(vis));
	for (int i=1; i<=n; ++i) {
		for (int j=n; j>=1; --j) {
			if (exi[j] && a[j]==i) {
				if (vis[j]) ++ans;
				else {
					for (int k=1; k<=j; ++k) vis[k]=true;
					for (int k=1; k<=j; ++k) ans+=exi[k];
				}
				exi[j]=false;
				break;
			}
		}
	}
	return ans;
}

int main() {
	freopen("dizalo.in", "r", stdin);
	freopen("dizalo.out", "w", stdout);
	n=read();
	q=read();
	for (int i=1; i<=n; ++i) a[i]=read();
	memset(rev, true, sizeof(rev));
	memset(exi, true, sizeof(exi));
	printf("%d ", calc());
	while (q--) {
		x=read();
		rev[x]=false;
		memcpy(exi, rev, sizeof(exi));
		printf("%d ", calc());
	}
	return 0;
}

