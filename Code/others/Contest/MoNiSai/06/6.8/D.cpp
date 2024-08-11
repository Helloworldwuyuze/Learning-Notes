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
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, a[N], st[N][20], t, maxx;

int gcd(int x,int y){ return y==0?x:gcd(y,x%y);}
int query(int l,int r){
	int t=log(r-l+1)/log(2);
	return gcd(st[l][t], st[r-(1<<t)+1][t]);
}
set<int> s[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; t=log(n)/log(2)+1;
	for(int i=1;i<=n;++i)	cin>>a[i], st[i][0]=a[i];
	for(int j=1;j<=t;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			st[i][j] = gcd(st[i][j-1], st[i+(1<<j-1)][j-1]);
	for(int i=1;i<=n;++i){
		int l=1, r=i, ll, rr;
		while(l<r){
			int mid=l+r>>1;
			if(query(mid, i)==a[i])	r=mid;
			else	l=mid+1;
		}
		ll = l, l=i, r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(query(i, mid)==a[i])	l=mid;
			else	r=mid-1;
		}
		rr = l;
		maxx=max(maxx ,rr-ll), s[rr-ll].insert(ll);
	}
	cout<<s[maxx].size()<<" "<<maxx<<endl;
	for(int i:s[maxx])	cout<<i<<" ";
	cout<<endl;
	return 0;
}