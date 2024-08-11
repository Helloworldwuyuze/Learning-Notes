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
ll n,a[N],vis[N],p=1,q=n;
pair<ll,ll> dfs(ll step) {
	if(p>q) return make_pair(0,0);
	if(step%2==1) {
		vis[a[p++]]++;
		pair<ll,ll> lans=dfs(step+1);
		if(vis[a[p-1]]==1) lans.first++;
		p--;
		vis[a[p]]--;
		vis[a[q--]]++;
		pair<ll,ll> rans=dfs(step+1);
		if(vis[a[q+1]]==1) rans.first++;
		q++;
		vis[a[q]]--;
		if(lans.first>rans.first) return lans;
		else if(lans.first<rans.first) return rans;
		else {
			if(lans.second<rans.second) return lans;
			else return rans;
		}
	}
	else {
		vis[a[p++]]++;
		pair<ll,ll> lans=dfs(step+1);
		if(vis[a[p-1]]==1) lans.second++;
		p--;
		vis[a[p]]--;
		vis[a[q--]]++;
		pair<ll,ll> rans=dfs(step+1);
		if(vis[a[q+1]]==1) rans.second++;
		q++;
		vis[a[q]]--;
		if(lans.second>rans.second) return lans;
		else if(lans.second<rans.second) return rans;
		else {
			if(lans.first<rans.first) return lans;
			else return rans;
		}
	}
}
int main() {
	freopen("kuglice.in","r",stdin);
	freopen("kuglice.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=20) {
		p=1,q=n;
		pair<ll,ll> pp=dfs(1);
		printf("%lld:%lld\n",pp.first,pp.second);
	}
	return 0;
}

