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
#include<unordered_map>

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
const int N = 2.5e5 + 10;
const int M = 1e7 + 10;

int a[N], n, k, d, ans;

int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
vector<int> v, g;
int p[M], idx;

void init(){
	for(int i=2;i<=M-10;++i){
		if(!p[i])	p[++idx]=i;
		for(int j=1;j<=idx&&p[j]*i<=M-10;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}
unordered_map<int,bool> ma;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k; init();
	int nn=n;
	for(int i=1;i<k;++i)
		cin>>a[i], ma[gcd(a[i],n)]=true;
	cin>>a[k];
	d=gcd(a[k],n);
	for(int i=1;i*i<=n;++i)
		if(n%i==0){
			v.pb(i);
			if(i*i!=n)	v.pb(n/i);
		}
	for(int i=1;i<=idx;++i){
		if(nn%p[i]==0)	g.pb(p[i]);
		while(nn%p[i]==0)	nn/=p[i];
		if(nn==1)	break;
	}
	if(nn!=1)	g.pb(nn);
	sort(v.begin(), v.end());
	for(int i=v.size()-1;i>=0;--i){
		if(ma[v[i]]){
			for(int j=0;j<g.size();++j)
				if(v[i]%g[j]==0)	ma[v[i]/g[j]]=true;
		}else if(d%v[i]==0)	ans=n/v[i];
	}
	cout<<ans<<endl;
	return 0;
}