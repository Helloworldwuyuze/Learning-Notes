#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
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
#define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int T, p, a, b, x, t;

int gcd(int x,int y){ return y==0?x:gcd(y,x%y);}
int ksm(int x,int m,int MOD){
	int ans = 1;
	for(;m;m>>=1,x=x*x%MOD)	if(m&1)	ans=ans*x%MOD;
	return ans;
}
unordered_map<int, int> ma;
int BSGS(int a,int b,int p){
	ma.clear();
	int nn = ceil(sqrt(p)), st = ksm(a, nn, p), res = b;
	for(int i=0;i<nn;++i)
		ma[res] = i + 1, res = res * a % p;
	res = st;
	for(int i=1;i<=nn;++i,res=res*st%p)
		if(ma[res])	return i*nn-ma[res]+1;
	return -1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>x>>t;
		// cout<<2*ksm(3, p-2, p)%p<<endl;
		if(x==t)	cout<<1<<endl;
		else if(a==1){
			t=((t-x)%p+p)%p;
			if(t%gcd(b,p))	cout<<-1<<endl;
			else if((t*ksm(b, p-2, p)+1)%p==0)	cout<<p<<endl;
			else	cout<<(t*ksm(b, p-2, p)+1)%p<<endl;
		}else if(a==0)	cout<<(b==t?2:-1)<<endl;
		else{
			b=(t+b*ksm((a-1+p)%p, p-2, p)%p)%p*ksm((x+b*ksm((a-1+p)%p, p-2, p)%p)%p, p-2, p)%p;
			// cout<<b<<" "<<209*ksm(949, p-2, p)%p<<" ";
			int res = BSGS(a, b, p);
			if(res!=-1)	cout<<(res+1)%p<<endl;
			else	cout<<-1<<endl;
		}
	}
	return 0;
}