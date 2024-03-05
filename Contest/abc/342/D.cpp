#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

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

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
#define int long long
const int N = 2e5 + 10;
const int M = sqrt(N)+10;

int p[N],cnt;
void init(){
	for(int i=2;i<=M;++i){
		if(!p[i])  p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=M;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0){ break;}
		}
	}
}
int n,a[N],_0,ans;
__int128 f[N];
map<pair<int,__int128>,int> ma;
map<pair<int,__int128>,bool> flag;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	// cout<<cnt<<endl;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0){ ++_0; continue;}
		for(int j=1;j<=cnt;++j){
			int s=0;
			while(a[i]%p[j]==0)	++s, a[i]/=p[j];
			f[i]|=((s&1)<<(j-1));
			if(a[i]==1)	break;
		}
		ma[mk(a[i],f[i])]++;
		// for(int j=1;j<=3;++j)	cout<<f[i].p[j];
		// cout<<endl;
	}
	// cout<<cnt<<endl;
	for(int i=1;i<=n;++i){
		if(a[i]==0)	continue;
		if(!flag[mk(a[i],f[i])])	ans+=ma[mk(a[i],f[i])]*(ma[mk(a[i],f[i])]-1)/2, flag[mk(a[i],f[i])]=true;
	}
	// cout<<ans<<endl;
	cout<<ans+(_0*(n-_0))+(_0*(_0-1))/2<<endl;
	return 0;
}