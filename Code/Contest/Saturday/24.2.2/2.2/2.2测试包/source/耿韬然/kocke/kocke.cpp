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

#define N 5005
int n, k, cur;
int ans;

int main() {
	freopen("dizalo.in", "r", stdin);
	freopen("dizalo.out", "w", stdout);
	n=read();
	k=read();
	printf("%d", n);
	return 0;
}

