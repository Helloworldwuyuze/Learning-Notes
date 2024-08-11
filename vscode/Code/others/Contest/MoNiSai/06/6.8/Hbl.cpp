#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 7;

int n,m,tot,ans=1;
pair<PII, PII> tmp;
int fa[N];
int find(int x){ return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1) ans=ans*x%MOD;
		x=x*x%MOD, m>>=1;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)   fa[i]=i;
	for(int i=1;i<=m;++i){
		cin>>tmp.fi.fi>>tmp.fi.se>>tmp.se.fi>>tmp.se.se;
		for(int j=1;j<=tmp.fi.se-tmp.fi.fi+1;++j){
			int x = tmp.fi.fi+j-1, y=tmp.se.fi+j-1;
			int fx = find(x), fy=find(y);
			if(fx==fy)	continue;
			fa[fx]=fy;
		}
	}
	for(int i=1;i<=n;++i)
		if(find(i)==i)  ans=ans*10%MOD;
	ans=ans*ksm(10,MOD-2)%MOD*9%MOD;
	cout<<ans<<endl;
	return 0;
}