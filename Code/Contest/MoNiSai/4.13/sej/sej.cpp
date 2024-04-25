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

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e7 + 10;
const int M = 2.5e5 + 10;
const int MOD = 1e9 + 7;

int p[N], cnt;
void init(){
	p[1]=1;
	for(int i=2;i<=N-10;++i){
		if(!p[i])	p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=N-10;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}
int a[M],n,m,sum[M],ans;
vector<int> v;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

signed main(){
	freopen("sej.in","r",stdin);
	freopen("sej.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		cin>>a[i];
	if(a[m]==0)	a[m]=n;
	int d=gcd(a[m],n);
//	cout<<d<<endl;
	for(int i=1;i<=cnt;++i){
		if(d%p[i]==0)	v.pb(p[i]);
		while(d%p[i]==0)	d/=p[i];
	}
	if(d!=1)	v.pb(d);
	for(int i=0;i<v.size();++i){
		for(int j=1;j<m;++j)
			if(a[j]%v[i]==0){
				v.erase(v.begin()+i, v.begin()+i+1);
				--i;
			}
	}
	for(int i=0;i<v.size();++i){
//		cout<<v[i]<<endl;
		if(i==0)	ans+=n/v[i], sum[1]=ans;
		else{
			ans+=n/v[i]; sum[1]+=n/v[i];
			for(int j=1;j<=i+1;++j){
				int tmp=(j%2?-1:1)*sum[j]/v[i];
				sum[j+1]+=abs(tmp), ans+=tmp;
			}
		}
//		for(int j=1;j<=i+1;++j)	cout<<sum[j]<<" ";
//		cout<<endl;
	}
	ans=0;
	for(int i=1;i<=v.size();++i)
		ans+=(i%2?1:-1)*sum[i];
	cout<<ans<<endl;
	return 0;
}
//97821761637600
