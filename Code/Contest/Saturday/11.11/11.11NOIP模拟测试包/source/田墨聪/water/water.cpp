#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
const int fx[]={0,0,1,-1};
const int fy[]={1,-1,0,0};
int n,m,k,h[105][105];
il bool checkout(int x,int y) {
	return (x<1)||(x>n)||(y<1)||(y>m);
}
bool xyz=0;
il int dfs(int x,int y) {
	h[x][y]=k+1;
	int ans=1;
	for(int i=0;i<4;i++) {
		int tx=x+fx[i],ty=y+fy[i];
		if(checkout(tx,ty)) xyz=1;
		if(checkout(x,y)||h[tx][ty]>=h[x][y]) continue;
		int tmp=dfs(tx,ty);
		ans+=tmp;
	}
	return ans;
}
signed main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int _=read();
	while(_--) {
		int maxn=0,minn=0x3f3f3f3f,ans=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
			h[i][j]=read();
			maxn=max(h[i][j],maxn);
			minn=min(h[i][j],minn);
		}
		bool ok=1;
		for(k=minn;k<=maxn;k++) {
			if(!ok) break;
			ok=0;
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
				xyz=0;
				if(h[i][j]>k) continue;
				ok=1;
				int tmp=dfs(i,j);
				if(!xyz) ans+=tmp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

