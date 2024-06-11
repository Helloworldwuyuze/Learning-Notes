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
const int N = 1e5 + 10;
const int M = 1e7 + 10;

int n, a[N], d[N], m, s[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i], d[i]=(a[i]-a[i-1])>0;
	d[1]=0;
	for(int i=2;i<=n;++i)	s[i]=s[i-1]+(a[i]==a[i-1]), d[i]+=d[i-1];
	// for(int i=1;i<=n;++i)
	// 	cout<<s[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;++i)
	// 	cout<<d[i]<<" ";
	// cout<<endl;
	while(m--){
		int l,r;
		cin>>l>>r;
		if(l==r){ cout<<"Yes"<<endl; continue;}
		int ll=l+1, rr=r; ++l;
		while(ll<rr){
			int mid=ll+rr>>1;
			// cout<<ll<<" "<<rr<<endl;
			if(d[r]-d[mid]==0)	rr=mid;
			else	ll=mid+1;
		}
		// cout<<ll<<" "<<s[ll-1]<<" "<<s[l-1]<<" "<<l-1<<endl;
		if(d[ll-1]-d[l-1]+s[ll-1]-s[l-1]==ll-l||ll==l)	cout<<"Yes"<<endl;
		else	cout<<"No"<<endl;
	}
	return 0;
}
