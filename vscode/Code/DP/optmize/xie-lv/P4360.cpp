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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,w[N],d[N],s,f[N];
int q[N],tail,head;

double X(int x){ return w[x];}
double Y(int x){ return w[x]*d[x];}
double slope(int x,int y){ return (Y(y)-Y(x))/(X(y)-X(x));}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>w[i]>>d[i], w[i]+=w[i-1];
	for(int i=n;i;--i)	s+=w[i]*d[i], d[i]+=d[i+1];
	q[head=tail=1]=0;
	for(int i=1;i<=n;++i){
		while(head<tail&&slope(q[head],q[head+1])>=d[i])	++head;
		int j=q[head]; f[i]=s-d[j]*w[j]-d[i]*(w[i]-w[j]);
		while(head<tail&&slope(q[tail],q[tail-1])<=slope(q[tail],i))	--tail;
		q[++tail]=i;
		// cout<<f[i]<<" ";
	}
	// cout<<endl;
	int ans=INF;
	for(int i=1;i<=n;++i)	ans=min(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}