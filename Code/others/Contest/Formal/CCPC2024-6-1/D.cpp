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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
const int MOD = 998244353;

int T,p,a,b,q,c,d,m,t;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>q>>c>>d>>m>>t;
		if(m<p){ cout<<m<<endl; continue;}
		int times = (p-m%p)/(m/p*(q-p)) + (bool)((p-m%p)%(m/p*(q-p)));
		int pack = m/p;
		while(pack*times*(a+c)+times*(b+d)<=t){
			// cout<<pack<<" "<<times<<endl;
			m+=pack*times*(q-p);
			t-=pack*times*(a+c)+times*(b+d);
			times = (p-m%p)/(m/p*(q-p)) + (bool)((p-m%p)%(m/p*(q-p)));
			pack = m/p;
		}
		times=t/(pack*(a+c)+b+d);
		// cout<<pack<<" "<<times<<endl;
		m+=times*pack*(q-p), t-=times*(pack*(a+c)+b+d);
		pack=max(0ll,(t-b-d)/(a+c)), m+=pack*(q-p);
		// cout<<pack<<" "<<times<<" "<<t<<endl;
		cout<<m<<endl;
	}
	return 0;
}
