#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=64,M=2e5+10;
int n,m;
struct R{
	int l,r,a;
}r[M];

bool vis[N];
int ans=0;

signed main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>r[i].l>>r[i].r>>r[i].a;
	for(int stat=0;stat<=(1<<n)-1;stat++){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(stat&(1<<(i-1))){
				for(int j=1;j<=m;j++){
					if(r[j].l<=i&&i<=r[j].r)vis[j]=1;
				}
			}
		}
		int s=0;
		for(int j=1;j<=m;j++){
			if(vis[j]){
				s+=r[j].a;
			}
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}
