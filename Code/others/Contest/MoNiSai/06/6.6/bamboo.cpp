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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 100 + 10;
const int M = 2e6;

int n,m,h[N],mx,up,ans;

int Div(int x,int y){ return x/y+(bool)(x%y);}

signed main(){
	// freopen("bamboo.in","r",stdin);
	// freopen("bamboo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>h[i], mx = max(mx, h[i]), m += h[i];
//	--m;
	if(mx*n<=m){ ans=mx+(m-mx*n)/n;}
	for(int r=mx, l=0;r;){
		l=1;
		for(int i=1;i<=n;++i)
			if(h[i]>=r)	l=max(l, Div(h[i], Div(h[i], r)));
			else	l=max(l, h[i]);
		up=0;
		for(int i=1;i<=n;++i)	up += Div(h[i], l);
//		cout<<l<<" "<<up<<endl;
		if(up*l<=m){ ans=max(ans,min(l+(m-up*l)/up, r));}
		r=l-1;
	}
	cout<<ans<<endl;
	return 0;
}
