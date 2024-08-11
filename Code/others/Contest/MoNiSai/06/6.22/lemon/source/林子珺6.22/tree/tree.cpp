#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,Q=5e5+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,q,a[N];
struct edge{
	int v,nxt;
}e[N*2];
int head[N],cnt=2;
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
int res=0;
void dfs(int u,int fa,int d,int k){
	if(d==k){
		res+=a[u];
		return;
	}
	for(int i=head[u];i;i=e[i].nxt){
		if(e[i].v!=fa){
			dfs(e[i].v,u,d+1,k);
		}
	}
}
int ans[Q];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=q;i++){
		int u,k;
		cin>>u>>k;
		dfs(u,0,0,k);
		ans[i]=res;res=0;
	}
	if(q<=1e4)for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	else {
		int xans=0;
		for(int i=1;i<=q;i++)xans^=ans[i];
		cout<<xans<<endl;
	}
	return 0;
} 
