#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<stack>

using namespace std;

#define int long long

const int N = 20 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m,ans;
int b[N],sum[N];
int l[N],r[N],a[N];

signed main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;++i)	cin>>l[i]>>r[i]>>a[i];
	for(int i=0;i<(1<<m);++i){
		int x=i,s=0,res=0;
		while(x)	b[++s]=x%2, x>>=1;
		for(int j=1;j<=m;++j)	sum[j]=sum[j-1]+b[j];
		for(int j=1;j<=n;++j)
			if(sum[r[j]]-sum[l[j]-1]>=1)	res+=a[j];
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

