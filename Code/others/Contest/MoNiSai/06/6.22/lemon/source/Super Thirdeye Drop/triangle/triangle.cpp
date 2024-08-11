#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define N 100005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
ll n,m,deg[N],ans=0;
int main() {
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) {
		int u=read(),v=read();
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++) ans+=deg[i]*(n-1-deg[i]);
	printf("%lld\n",n*(n-1)*(n-2)/6-ans/2);
	return 0;
}

