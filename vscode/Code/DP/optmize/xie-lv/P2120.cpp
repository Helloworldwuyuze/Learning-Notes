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
const int INF = 1e18;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n,x[N],p[N],c[N],d[N],s[N],f[N];
int q[N],tail,head;

double X(int x){ return d[x];}
double Y(int x){ return f[x]+s[x];}
int sgn(int x){return x>0?1:-1;}
double slope(int x,int y){
	if(abs(X(x)-X(y))<=eps)	return sgn(Y(y)-Y(x))*INF;
	return (Y(y)-Y(x))/(X(y)-X(x));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>x[i]>>p[i]>>c[i];
	for(int i=1;i<=n;++i)	d[i]=d[i-1]+p[i], s[i]=s[i-1]+p[i]*x[i];
	q[tail=head=1]=0;
	for(int i=1;i<=n;++i){
		while(head<tail&&slope(q[head],q[head+1])<=x[i])	++head;
		int j=q[head]; f[i]=f[j]+c[i]+x[i]*(d[i]-d[j])-s[i]+s[j];
		while(head<tail&&slope(q[tail],q[tail-1])>=slope(q[tail],i))	--tail;
		q[++tail]=i;
		// cout<<f[i]<<" "<<j<<" "<<f[j]<<" "<<c[i]<<" "<<x[i]<<" "<<d[i]<<" "<<d[j]<<" "<<s[i]<<" "<<s[j]<<endl;
		// for(int i=head;i<=tail;++i)	cout<<q[i]<<" "<<slope(q[i],q[i+1])<<endl;
		// cout<<endl;
	}
	int ans=INF;
	for(int i=n;i;--i){
		ans=min(ans,f[i]);
		if(p[i])	break;
	}
	cout<<ans<<endl;
	return 0;
}