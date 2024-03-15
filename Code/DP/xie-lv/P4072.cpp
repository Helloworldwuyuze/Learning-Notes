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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e3 + 10;
const int M = 1e6 + 10;

int n,m,f[N],q[N],tail,head,c[N],g[N];
double X(int x){ return c[x]; }
double Y(int x){ return g[x]+c[x]*c[x]; }
double slope(int x,int y){ return (Y(x)-Y(y))/(X(x)-X(y));}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>c[i], c[i]+=c[i-1], g[i]=c[i]*c[i];
	for(int l=1;l<m;++l){
		q[tail=head=1]=l;
		for(int i=l+1;i<=n;++i){
			while(head<tail&&slope(q[head],q[head+1])<=2*c[i])	++head;
			// cout<<slope(q[head],q[head+1])<<" "<<c[i]<<" ";
			int j=q[head]; f[i]=g[j]+(c[i]-c[j])*(c[i]-c[j]);
			while(head<tail&&slope(q[tail],q[tail-1])>=slope(q[tail],i))	--tail;
			q[++tail]=i;
			// cout<<g[i]<<" "<<f[i]<<endl;
		}
		// cout<<endl;
		for(int i=1;i<=n;++i)	g[i]=f[i];
	}
	cout<<f[n]*m-c[n]*c[n]<<endl;	
	return 0;
}