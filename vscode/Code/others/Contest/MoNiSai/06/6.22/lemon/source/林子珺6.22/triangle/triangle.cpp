#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp_make_pair
int n,m,ans;
int d[N];
signed main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ans=n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++)d[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		ans-=(n-d[u]-d[v]);
		d[u]++,d[v]++;
	}
	cout<<ans<<endl;
	return 0;
}

