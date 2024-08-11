#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
#define il inline
#define N 100005
#define sn 318
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,q,dfn[N],tot,rev[N],siz[N],d[N],b[500005];
vector<int> g[N];
vector<int> ask[N];
int a[N];
struct block {
    int val[N],pos[N],L[sn+10],R[sn+10],tag[sn+10],vis[sn+10][2*N];
    inline void init() {
    	for(int i=1;i<=n;i++) val[dfn[i]]=d[i]+100000;
        for(int i=1;i<=sn;i++) {
            L[i]=(i-1)*(n/sn)+1;
            R[i]=i*(n/sn);
        }
        R[sn]=n;
        for(int i=1;i<=sn;i++) {
            for(int j=L[i];j<=R[i];j++) {
                pos[j]=i;
                vis[i][val[j]]+=a[rev[j]];
            }
        }
    }
    il void modify(int l,int r,int k){
        int p=pos[l],q=pos[r];
        if(p==q) {
            for(int i=l;i<=r;i++){
                vis[p][val[i]]-=a[rev[i]];
                val[i]+=k;
                vis[p][val[i]]+=a[rev[i]];
            }
        }
        else {
            for(int i=l;i<=R[p];i++) {
                vis[p][val[i]]-=a[rev[i]];
                val[i]+=k;
                vis[p][val[i]]+=a[rev[i]];
            }
            for(int i=p+1;i<q;i++) tag[i]+=k;
            for(int i=L[q];i<=r;i++) {
                vis[q][val[i]]-=a[rev[i]];
                val[i]+=k;
                vis[q][val[i]]+=a[rev[i]];
            }
        }
    }
    il ll query(int l,int r,int k) {
    	k+=100000;
        int p=pos[l],q=pos[r];
        if(p==q) {
        	ll ans=0;
            for(int i=l;i<=r;i++) if(val[i]+tag[p]==k) ans+=a[rev[i]];
            return ans;
        }
        else {
        	ll ans=0;
            for(int i=l;i<=R[p];i++) if(val[i]+tag[p]==k) ans+=a[rev[i]];
            for(int i=p+1;i<q;i++) if(vis[i][k-tag[i]]) ans+=vis[i][k-tag[i]];
            for(int i=L[q];i<=r;i++) if(val[i]+tag[q]==k) ans+=a[rev[i]];
            return ans;
        }
    }
};
block bl;
il void dfs1(int u,int f) {
	tot++;
	siz[u]=1;dfn[u]=tot;rev[tot]=u;d[u]=d[f]+1;
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}
il void dfs2(int u,int f) {
	for(int i=0;i<ask[u].size();i++) {
		int k=b[ask[u][i]];
		b[ask[u][i]]=bl.query(1,n,k+1);
	}
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(v==f) continue;
		bl.modify(1,n,1);
		bl.modify(dfn[v],dfn[v]+siz[v]-1,-2);
		dfs2(v,u);
		bl.modify(dfn[v],dfn[v]+siz[v]-1,2);
		bl.modify(1,n,-1);
	}
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	for(int i=1;i<=q;i++) {
		int u=read(),k=read();
		ask[u].push_back(i);
		b[i]=k;
	}
	bl.init();
	dfs2(1,0);
	if(q<=10000) for(int i=1;i<=q;i++) printf("%d\n",b[i]);
	else {
		unsigned ll ans=0;
		for(unsigned ll i=1;i<=q;i++) ans^=i*(unsigned ll)(b[i]);
		cout<<ans<<endl;
	}
	return 0;
}

