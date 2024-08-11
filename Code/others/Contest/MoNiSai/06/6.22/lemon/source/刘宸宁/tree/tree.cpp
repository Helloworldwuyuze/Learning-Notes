#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=1e5+5;
int head[N],tot,a[N],n,m,dis[N],ans[N*5],mxn[N];
struct Graph{int ver,nxt;}g[N<<1];
struct Input{ll p,k,id;}b[N*5];
inline void add(int x,int y){g[++tot].ver=y,g[tot].nxt=head[x];head[x]=tot;}
inline bool cmp(Input x,Input y){if(x.p==y.p) return x.k<y.k;return x.p<y.p;}
inline void dfs(ll x,ll fa,ll dep,ll mx){
	dis[dep]+=a[x];if(dep>=mx) return;
	for(int i=head[x];i;i=g[i].nxt){
		ll y=g[i].ver;if(y==fa) continue;
		dfs(y,x,dep+1,mx);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);add(u,v),add(v,u);}
	for(int i=1;i<=m;i++){scanf("%d%d",&b[i].p,&b[i].k);b[i].id=i;mxn[b[i].p]=max(mxn[b[i].p],(int)b[i].k);}
	sort(b+1,b+1+m,cmp);
	ll j=1;
	for(int i=1;i<=n;i++){
		if(j>m) break;
		while(b[j].p<i&&j<=m) j++;
		for(int k=0;k<=n;k++) dis[k]=0;
		dfs(i,0,0,mxn[i]);
		while(b[j].p<=i&&j<=m) ans[b[j].id]=dis[b[j].k],j++;
	}
	if(m<=10000)for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	else{
		long long sum=0;
		for(int i=1;i<=m;i++) sum=sum^(1ll*i*ans[i]);
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4
1 2 3 4
1 2
1 3
1 4
1 0
1 1
2 1
4 100
*/
