#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int M = 2e3 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,k,T;
int f[N][N],w[N];
int fa[N];
bool isfa[N];

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)	isfa[i]=false;
		
		for(int i=2;i<=n;++i)	cin>>fa[i], isfa[fa[i]]=true;
		for(int i=2;i<=n;++i)	cin>>w[i];
		
		for(int i=1;i<=n;++i)
			if(!isfa[i])	for(int j=0;j<=n;++j)	f[j][i]=INF;
			else	for(int j=0;j<=n;++j)	f[j][i]=0;
		for(int t=1;t<=n;++t)
			for(int x=2;x<=n;++x)
				f[t][fa[x]]+=min(f[t-1][x],w[x]);
		
		int i=1,sum=f[0][1];
		while(i<=n&&sum<k)	sum+=f[i++][1];
		if(sum>=k)	cout<<i-1<<endl;
		else	cout<<(int)(n+ceil(1.0*(k-sum)/f[n][1]))<<endl;
	}
	return 0;
}

